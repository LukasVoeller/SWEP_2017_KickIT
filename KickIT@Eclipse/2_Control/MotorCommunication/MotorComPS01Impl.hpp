#ifndef MOTORCOM_IMPL_PS01_HPP
#define MOTORCOM_IMPL_PS01_HPP

#include <net/if.h>
#include <linux/can.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 	//For sockets
#include <sys/socket.h> //For sockets

#include "../../5_DataType/RowEnum.hpp"
#include "_MotorCommunicatorInterface.hpp"

class MotorComPS01Impl: public MotorCommunicatorInterface {

public:
	MotorComPS01Impl(Row r);
	void linearMovement(int position);

protected:
	void driverInit();
};

#endif //MOTORCOM_IMPL_PS01_HPP