/*
//
//
#################################################################################################
#											Class Joint											#
#################################################################################################
//
//
*/

#include <ClassJoint.h>

Joint::Joint()
{
	// 
}

Joint::Joint(std::string _id, std::string _type, double _value, double _min, double _max)
{
	id = _id;
	type = _type;
	value = _value;
	min = _min;
	max = _max;
	SetUnitForJoint();
}

Joint::~Joint()
{
	// Destroy
}


void Joint::SetUnitForJoint()
{
	if (type == "translational")
	{
		unit = "m";
	}
	else
	{
		unit = "deg";
	}
}