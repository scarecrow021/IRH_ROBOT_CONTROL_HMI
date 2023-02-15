/**
*	\class		Joint
*	\brief		Joint Class for data type
*	\author		Soumik SARKAR @ ITER Organization
*/

#pragma once
#ifndef CLASS_JOINT_H
#define CLASS_JOINT_H

//----------------
//	START HERE
//----------------

#include <cppHeaders.h>

/**
* \class	Joint
* \brief	Members: strings: id, type, unit; doubles: value, min, max
* \brief	Constructor: Empty or (id,type,value,min,max)
*/
class Joint
{
public:
	std::string id; // ID of current joint (Name of Joint)
	std::string type; // Type of Joint (Rotational, Translational, etc)
	double value; // Current Value of Current Joint (Angular or Linear)
	double min; // Minimum Limit of Current Joint
	double max; // Maximum Limit of Current Joint
	std::string unit; // Dimensional Unit of Current Joint (Degree or Metre)

	Joint();
	Joint(std::string _id, std::string _type, double _value, double _min, double _max);
	void SetUnitForJoint();
	~Joint();
};

//----------------
//	 END HERE
//----------------

#endif // CLASS_JOINT_H