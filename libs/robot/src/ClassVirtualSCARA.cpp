/*
//
//
#################################################################################################
#										Class VirtualSCARA										#
#################################################################################################
//
//
*/

#include <ClassVirtualSCARA.h>

/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::SetLengths(double _l1, double _l2, double _l3)
{
	l1 = _l1;
	l2 = _l2;
	l3 = _l3;
	outBound = l1 + l2;
	inBound = l1 - l2;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::AddJoint(std::string _id, std::string _type, double _value, double _min, double _max)
{
	Joint _joint(_id, _type, _value, _min, _max);
	joints.push_back(_joint);
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::CalculateCurrentPoint()
{
	currentPoint.x = (l1 * cd(joints.at(0).value)) + (l2 * cd(joints.at(0).value + joints.at(1).value));
	currentPoint.y = (l1 * sd(joints.at(0).value)) + (l2 * sd(joints.at(0).value + joints.at(1).value));
	currentPoint.z = l3 - joints.at(3).value;
	currentTheta = joints.at(2).value;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string VirtualSCARA::PrintJointID(int _jointNum)
{
	return joints.at(_jointNum).id;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string VirtualSCARA::PrintJointType(int _jointNum)
{
	return joints.at(_jointNum).type;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string VirtualSCARA::PrintJointUnit(int _jointNum)
{
	return joints.at(_jointNum).unit;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
double VirtualSCARA::GiveJointValue(int _jointNum)
{
	return joints.at(_jointNum).value;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
double VirtualSCARA::GiveJointMin(int _jointNum)
{
	return joints.at(_jointNum).min;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
double VirtualSCARA::GiveJointMax(int _jointNum)
{
	return joints.at(_jointNum).max;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string VirtualSCARA::PrintJointValue(int _jointNum)
{
	char t[10];
	std::sprintf(t,"%0.2f",joints.at(_jointNum).value);
	return t;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string VirtualSCARA::PrintJointMin(int _jointNum)
{
	char t[10];
	std::sprintf(t, "%0.2f", joints.at(_jointNum).min);
	return t;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string VirtualSCARA::PrintJointMax(int _jointNum)
{
	char t[10];
	std::sprintf(t, "%0.2f", joints.at(_jointNum).max);
	return t;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::UpdateJoint(int _jointNum, double transStep, double rotStep)
{
	if (joints.at(_jointNum).type == "translational")
	{
		if (CheckWithinLimits(_jointNum, joints.at(_jointNum).value + transStep))
		{
			joints.at(_jointNum).value = joints.at(_jointNum).value + transStep;
		}
	}
	else
	{
		if (CheckWithinLimits(_jointNum, joints.at(_jointNum).value + rotStep))
		{
			joints.at(_jointNum).value = joints.at(_jointNum).value + rotStep;
		}
	}
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
bool VirtualSCARA::CheckWithinLimits(int jointNum, double value)
{
	if (joints.at(jointNum).min <= value && value <= joints.at(jointNum).max)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::CalculateIK()
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
	// else do nothing!
	// TODO CASE q2 = 0, 180, -180
}


/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::SetDesiredPoint(int axis, int direction, double delta)
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
bool VirtualSCARA::CheckWithinWorkspace()
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


/**
* ----------------------------------------------------------------------------------------------------------------
*/
void VirtualSCARA::Restart()
{
	joints.clear();
}
