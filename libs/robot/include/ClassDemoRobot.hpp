/**
*	\class		Demo Robot
*	\brief		Demo Robot Class
*	\author		Soumik SARKAR @ ITER Organization
*/

#pragma once
#ifndef CLASS_DEMO_ROBOT_HPP
#define CLASS_DEMO_ROBOT_HPP

#include <cppHeaders.hpp>
#include <ClassRobot.hpp>

/**
* DemoRobot has 4 joints [q1, q2, q3, q4] but in vector<Joint>.
* DemoRobot ee has two points: Point currentPoint, desiredPoint.
* DemoRobot ee has two angles: double currentTheta, desiredTheta.
* currentTheta is q3.
* x = l1.cos(q1) + l2.cos(q1+q2)
* y = l1.sin(q1) + l2.sin(q1+q2)
* z = l3 - q4
* theta = q3
* Constructor auto initialises: numberOfJoints = 4
* l1 = 0.8, l2 = 0.6, l3 = 0.425 is constant
*/
class DemoRobot : public Robot
{
public:
	double l1 = 0.8, l2 = 0.6, l3 = 0.425;
	double currentTheta, desiredTheta;
	double inBound, outBound;

	DemoRobot();
	~DemoRobot();
	void CalculateCurrentPoint();
	void CalculateIK();
	void SetDesiredPoint(int axis, int direction, double delta);
	bool CheckWithinWorkspace();
	void SetJointTarget(double j[4]);

};

#endif // CLASS_DEMO_ROBOT_HPP