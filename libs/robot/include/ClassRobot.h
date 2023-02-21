/**
*	\class		Robot
*	\brief		Robot Class for computation handling
*	\author		Soumik SARKAR @ ITER Organization
*/

#pragma once


#ifndef CLASS_ROBOT_H
#define CLASS_ROBOT_H

#include <cppHeaders.h>
#include <ClassJoint.h>
#include <ClassPoint.h>
#include <mymath.h>
#include <rapi.h>
#include <rapi_utility.h>

class Robot
{
public:
	enum
	{
		JOINT_1,
		JOINT_2,
		JOINT_3,
		JOINT_4
	};
	std::string robotName;
	int numberOfJoints;
	std::vector<Joint> joints;
	Point currentPoint, desiredPoint;
	double translationStep = 0.01, rotationStep = 30.00;

	std::string PrintRobotName();
	void AddToJointVector(Joint j);
	void GetRobotData();
	void MoveRobot();
	std::string PrintJointID(int _jointNum);
	std::string PrintJointType(int _jointNum);
	std::string PrintJointUnit(int _jointNum);
	double GiveJointValue(int _jointNum);
	double GiveJointMin(int _jointNum);
	double GiveJointMax(int _jointNum);
	std::string PrintJointValue(int _jointNum);
	std::string PrintJointMin(int _jointNum);
	std::string PrintJointMax(int _jointNum);
	bool CheckWithinLimits(int jointNum, double value);
	void UpdateJoint(int _jointNum, double transStep, double rotStep);
	void Restart();
	void SetNewJointTarget(int _jointNum, double newJoint);
	
};

#endif // CLASS_ROBOT_H