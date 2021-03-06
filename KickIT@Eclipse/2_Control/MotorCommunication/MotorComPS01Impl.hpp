/**
 * @file MotorComPS01Impl.hpp
 *
 */
#ifndef MOTORCOM_IMPL_PS01_HPP
#define MOTORCOM_IMPL_PS01_HPP

#include <net/if.h>
#include <linux/can.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 	//For sockets
#include <sys/socket.h> //For sockets
#include "_MotorCommunicatorInterface.hpp"

/**MotorComPS01Impl class
 *
 */
class MotorComPS01Impl: public MotorCommunicatorInterface {
public:
	/**MotorComPS01Impl constructor
	 *
	 */
	MotorComPS01Impl();

	void linearMovement(int position);

protected:
	void driverInit();
};

#endif //MOTORCOM_IMPL_PS01_HPP
