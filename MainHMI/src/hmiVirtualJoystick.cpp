#include "mainhmi.h"
#include "./ui_mainhmi.h"



void MainHMI::VirtualJointMove(int axis, int direction)
{
	switch (hmi->robotSelector->currentIndex())
	{
	case NO_ROBOT:
		break;

	case ROBOT_ONE:
		switch (axis)
		{
		case X_AXIS:
			if (hmi->vjMotionSelectX->currentIndex() == TRANSLATION_REQUEST)
			{
				scara.SetDesiredPoint(X_AXIS, direction, delta);
				scara.CalculateIK();
			}
			// else do nothing!
			break;

		case Y_AXIS:
			if (hmi->vjMotionSelectY->currentIndex() == TRANSLATION_REQUEST)
			{
				scara.SetDesiredPoint(Y_AXIS, direction, delta);
				scara.CalculateIK();
			}
			// else do nothing!
			break;

		case Z_AXIS:
			if (hmi->vjMotionSelectZ->currentIndex() == TRANSLATION_REQUEST)
			{
				scara.SetDesiredPoint(Z_AXIS, direction, delta);
				scara.CalculateIK();
			}
			else
			{
				// Bad way to do this!
				if (direction == NEGATIVE_DIRECTION)
				{
					scara.currentTheta = scara.currentTheta - delta;
				}
				else
				{
					scara.currentTheta = scara.currentTheta + delta;
				}
				scara.joints.at(2).value = scara.currentTheta;
			}
			break;

		default: break;
		}
		UpdateRobotInfo();
		break;

	case ROBOT_TWO:
		switch (axis)
		{
		case X_AXIS:
			if (hmi->vjMotionSelectX->currentIndex() == TRANSLATION_REQUEST)
			{
				demoRobot.SetDesiredPoint(X_AXIS, direction, delta);
				demoRobot.CalculateIK();
			}
			// else do nothing!
			break;

		case Y_AXIS:
			if (hmi->vjMotionSelectY->currentIndex() == TRANSLATION_REQUEST)
			{
				demoRobot.SetDesiredPoint(Y_AXIS, direction, delta);
				demoRobot.CalculateIK();
			}
			// else do nothing!
			break;

		case Z_AXIS:
			if (hmi->vjMotionSelectZ->currentIndex() == TRANSLATION_REQUEST)
			{
				demoRobot.SetDesiredPoint(Z_AXIS, direction, delta);
				demoRobot.CalculateIK();
			}
			else
			{
				// Bad way to do this!
				if (direction == NEGATIVE_DIRECTION)
				{
					demoRobot.currentTheta = scara.currentTheta - delta;
				}
				else
				{
					demoRobot.currentTheta = scara.currentTheta + delta;
				}
				demoRobot.joints.at(2).value = scara.currentTheta;
			}
			break;

		default: break;
		}
		UpdateRobotInfo();
		break;

	default: break;
	}
}



void MainHMI::vjPlusXClicked()
{
	VirtualJointMove(X_AXIS, POSITIVE_DIRECTION);
}

void MainHMI::vjPlusYClicked()
{
	VirtualJointMove(Y_AXIS, POSITIVE_DIRECTION);
}

void MainHMI::vjPlusZClicked()
{
	VirtualJointMove(Z_AXIS, POSITIVE_DIRECTION);
}

void MainHMI::vjMinusXClicked()
{
	VirtualJointMove(X_AXIS, NEGATIVE_DIRECTION);
}

void MainHMI::vjMinusYClicked()
{
	VirtualJointMove(Y_AXIS, NEGATIVE_DIRECTION);
}

void MainHMI::vjMinusZClicked()
{
	VirtualJointMove(Z_AXIS, NEGATIVE_DIRECTION);
}
