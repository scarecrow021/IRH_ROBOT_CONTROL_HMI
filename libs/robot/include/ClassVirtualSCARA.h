/**
*	\class		VirtualSCARA
*	\brief		Virtual SCARA Class
*	\author		Soumik SARKAR @ ITER Organization
*/

#pragma once
#ifndef CLASS_VIRTUAL_SCARA_H
#define CLASS_VIRTUAL_SCARA_H

#include <cppHeaders.h>
#include <ClassJoint.h>
#include <ClassPoint.h>
#include <mymath.h>

class VirtualSCARA
{
	

public:
	int numberOfJoints = 4;
	std::vector<Joint> joints;
	double l1, l2, l3;
	Point currentPoint, desiredPoint;
	double currentTheta, desiredTheta;
	double desiredJointVals[4];
	double inBound, outBound;


	void SetLengths(double _l1, double _l2, double _l3);
	void AddJoint(std::string _id, std::string _type, double _value, double _min, double _max);
	void CalculateCurrentPoint();
	std::string PrintJointID(int _jointNum);
	std::string PrintJointType(int _jointNum);
	std::string PrintJointUnit(int _jointNum);
	double GiveJointValue(int _jointNum);
	double GiveJointMin(int _jointNum);
	double GiveJointMax(int _jointNum);
	std::string PrintJointValue(int _jointNum);
	std::string PrintJointMin(int _jointNum);
	std::string PrintJointMax(int _jointNum);
	void UpdateJoint(int _jointNum, double transStep, double rotStep);
	bool CheckWithinLimits(int jointNum, double value);
	void CalculateIK();
	void SetDesiredPoint(int axis, int direction, double delta);
	bool CheckWithinWorkspace();
	void Restart();
};





#endif // CLASS_VIRTUAL_SCARA_H