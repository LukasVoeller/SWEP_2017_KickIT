#include "VirtualKickerWindow.hpp"
#include "../DataType/Vec2.hpp"

//Alle angaben in cm
int scale = 7;

double goalSize = 21 * scale;
double tableDimensionY = 68 * scale;
double tableDimensionX = 111.5 * scale;
double goalToKeeper = 3.5 * scale;
double goalToDefense = 18.5 * scale;

VirtualKickerWindow::VirtualKickerWindow() :
		tc(NULL) {
	setMouseTracking(true);

	topLeft = new QPoint(TABLE_MARGIN, TABLE_MARGIN);

	keeperBar = new QLine(topLeft->x() + goalToKeeper, topLeft->y() - 30,
			topLeft->x() + goalToKeeper, topLeft->y() + tableDimensionY + 30);
	keeper = new QPoint(keeperBar->x1(), keeperBar->y1() + keeperBar->dy() / 2);

	defenseBar = new QLine(topLeft->x() + goalToDefense, topLeft->y() - 30,
			topLeft->x() + goalToDefense, topLeft->y() + tableDimensionY + 30);
	defense[0] = new QPoint(defenseBar->x1(),
			defenseBar->y1() + (defenseBar->dy() / 3) * 2);
	defense[1] = new QPoint(defenseBar->x1(),
			defenseBar->y1() + defenseBar->dy() / 3);
}

void VirtualKickerWindow::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	QPen myPen(Qt::black, 2, Qt::SolidLine);
	painter.setPen(myPen);

	painter.drawRect(topLeft->x() - 30,
			topLeft->y() + tableDimensionY / 2 - goalSize / 2, 30, goalSize);//Tor
	painter.drawRect(topLeft->x(), topLeft->y(), tableDimensionX,
			tableDimensionY);				//Tisch

	painter.drawLine(*keeperBar);
	painter.drawLine(*defenseBar);

	painter.setPen(QPen(Qt::red, 20, Qt::DashDotLine, Qt::RoundCap));
	painter.drawPoint(*keeper);
	painter.drawPoint(*defense[0]);
	painter.drawPoint(*defense[1]);

	painter.setPen(QPen(Qt::blue, 20, Qt::DashDotLine, Qt::RoundCap));
	for (long unsigned int i = 0; i < mouseTrail.size(); i++) {
		painter.drawPoint(*mouseTrail[i]);
	}
}

void VirtualKickerWindow::mouseMoveEvent(QMouseEvent* e) {
	if ((abs(e->pos().x() - lastAdded.x()) + abs(e->pos().y() - lastAdded.y()))
			> 20 && (e->buttons() & Qt::LeftButton)) {
		mouseTrail.push_back(new QPoint(e->pos().x(), e->pos().y()));
		lastAdded.setX(e->pos().x());
		lastAdded.setY(e->pos().y());
		tc->setBallPos(e->pos().x(), e->pos().y());
		repaint();
	}
}

void VirtualKickerWindow::mouseReleaseEvent(QMouseEvent* e) {
	mouseTrail.clear();
}

void VirtualKickerWindow::setKeeper(float pos) {
	keeper->setY(pos);
	repaint();
}

void VirtualKickerWindow::setDefense(float pos) {
	defense[0]->setY(pos);
	defense[1]->setY(pos + defenseBar->dy() / 3);
	repaint();
}

void VirtualKickerWindow::setTableController(InterfaceTableController* t) {
	tc = t;
}

Vec2* VirtualKickerWindow::getKeeperPositionalVector() {
	return new Vec2(keeperBar->x1(), 0);
}

Vec2* VirtualKickerWindow::getDefensePositionalVector() {
	return new Vec2(defenseBar->x1(), 0);
}

float VirtualKickerWindow::getDDist() {
	return defenseBar->dy() / 3;
}

