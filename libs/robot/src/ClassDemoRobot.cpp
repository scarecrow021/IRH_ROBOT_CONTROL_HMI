/*
//
//
#################################################################################################
#										Class DemoRobot											#
#################################################################################################
//
//
*/

#include <ClassDemoRobot.h>


/**
* ----------------------------------------------------------------------------------------------------------------
*/
DemoRobot::DemoRobot()
{
	numberOfJoints = 4;
	outBound = l1 + l2;
	inBound = l1 - l2;
}


/**
* ----------------------------------------------------------------------------------------------------------------
*/
DemoRobot::~DemoRobot()
{
	// - Kill
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void DemoRobot::CalculateCurrentPoint()
{
	currentPoint.x = (l1 * cd(joints.at(0).value)) + (l2 * cd(joints.at(0).value + joints.at(1).value));
	currentPoint.y = (l1 * sd(joints.at(0).value)) + (l2 * sd(joints.at(0).value + joints.at(1).value));
	currentPoint.z = l3 - joints.at(3).value;
	currentTheta = joints.at(2).value;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void DemoRobot::CalculateIK()
{
	if (CheckWithinWorkspace())
	{
		if (joints.at(1).value < 0.0)
		{
			double intermediateValue = (pow(desiredPoint.x, 2) + pow(desiredPoint.y, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2);
			joints.at(1).value = -atan(sqrt(1 - pow(intermediateValue, 2)) / intermediateValue);
			joints.at(0).value = atan((desiredPoint.x * l2 * sin(joints.at(1).value) + desiredPoint.y * (l1 + l2 * cos(joints.at(1).value))) / (desiredPoint.x * (l1 + l2 * cos(joints.at(1).value)) - desiredPoint.y * l2 * sin(joints.at(1).value)));
			// At this point the joint angles are in radians, therefore need to convert them to degrees for HMI!
			joints.at(0).value = ToDegree(joints.at(0).value);
			joints.at(1).value = ToDegree(joints.at(1).value);
			CalculateCurrentPoint();
		}
		else
		{
			double intermediateValue = (pow(desiredPoint.x, 2) + pow(desiredPoint.y, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2);
			joints.at(1).value = atan(sqrt(1 - pow(intermediateValue, 2)) / intermediateValue);
			joints.at(0).value = atan((-desiredPoint.x * l2 * sin(joints.at(1).value) + desiredPoint.y * (l1 + l2 * cos(joints.at(1).value))) / (desiredPoint.x * (l1 + l2 * cos(joints.at(1).value)) + desiredPoint.y * l2 * sin(joints.at(1).value)));
			// At this point the joint angles are in radians, therefore need to convert them to degrees for HMI!
			joints.at(0).value = ToDegree(joints.at(0).value);
			joints.at(1).value = ToDegree(joints.at(1).value);
			CalculateCurrentPoint();
		}
	}
	MoveRobot();
	// else do nothing!
	// TODO CASE q2 = 0, 180, -180
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void DemoRobot::SetDesiredPoint(int axis, int direction, double delta)
{
	if (axis == 0)
	{
		if (direction == -1)
		{
			desiredPoint.Copy(currentPoint);
			desiredPoint.x = desiredPoint.x - delta;

		}
		else
		{
			desiredPoint.Copy(currentPoint);
			desiredPoint.x = desiredPoint.x + delta;
		}
	}
	else if (axis == 1)
	{
		if (direction == -1)
		{
			desiredPoint.Copy(currentPoint);
			desiredPoint.y = desiredPoint.y - delta;

		}
		else
		{
			desiredPoint.Copy(currentPoint);
			desiredPoint.y = desiredPoint.y + delta;
		}
	}
	else if (axis == 2)
	{
		if (direction == -1)
		{
			desiredPoint.Copy(currentPoint);
			desiredPoint.z = desiredPoint.z - delta;
		}
		else
		{
			desiredPoint.Copy(currentPoint);
			desiredPoint.z = desiredPoint.z + delta;
		}
	}

}


/**
* ----------------------------------------------------------------------------------------------------------------
*/
bool DemoRobot::CheckWithinWorkspace()
{

	if ((inBound < hypot(desiredPoint.x, desiredPoint.y)) && (hypot(desiredPoint.x, desiredPoint.y) < outBound))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
void DemoRobot::SetJointTarget(double j[4])
{
	SetNewJointTarget(JOINT_1, j[JOINT_1]);
	SetNewJointTarget(JOINT_2, j[JOINT_2]);
	SetNewJointTarget(JOINT_3, j[JOINT_3]);
	SetNewJointTarget(JOINT_4, j[JOINT_4]);
	MoveRobot();
}
*/
