#include "mainhmi.h"
#include "./ui_mainhmi.h"



void MainHMI::ShowDemoRobotInfo()
{
	hmi->joint1->SetJointInfo(demoRobot.PrintJointMin(JOINT_1), demoRobot.PrintJointMax(JOINT_1), demoRobot.PrintJointValue(JOINT_1));
	hmi->joint2->SetJointInfo(demoRobot.PrintJointMin(JOINT_2), demoRobot.PrintJointMax(JOINT_2), demoRobot.PrintJointValue(JOINT_2));
	hmi->joint3->SetJointInfo(demoRobot.PrintJointMin(JOINT_3), demoRobot.PrintJointMax(JOINT_3), demoRobot.PrintJointValue(JOINT_3));
	hmi->joint4->SetJointInfo(demoRobot.PrintJointMin(JOINT_4), demoRobot.PrintJointMax(JOINT_4), demoRobot.PrintJointValue(JOINT_4));
}

void MainHMI::SetDemoRobotTitleInfo()
{
	hmi->joint1->SetJointTitle(demoRobot.PrintJointID(JOINT_1), demoRobot.PrintJointType(JOINT_1), demoRobot.PrintJointUnit(JOINT_1));
	hmi->joint2->SetJointTitle(demoRobot.PrintJointID(JOINT_2), demoRobot.PrintJointType(JOINT_2), demoRobot.PrintJointUnit(JOINT_2));
	hmi->joint3->SetJointTitle(demoRobot.PrintJointID(JOINT_3), demoRobot.PrintJointType(JOINT_3), demoRobot.PrintJointUnit(JOINT_3));
	hmi->joint4->SetJointTitle(demoRobot.PrintJointID(JOINT_4), demoRobot.PrintJointType(JOINT_4), demoRobot.PrintJointUnit(JOINT_4));
}

void MainHMI::SetDemoRobotEndEffectorPose()
{
	demoRobot.CalculateCurrentPoint();
	hmi->eeTransX->setValue(demoRobot.currentPoint.x);
	hmi->eeTransY->setValue(demoRobot.currentPoint.y);
	hmi->eeTransZ->setValue(demoRobot.currentPoint.z);
	hmi->eeRotZ->setValue(demoRobot.currentTheta);
	hmi->eeRotX->setHidden(true);
	hmi->eeRotY->setHidden(true);
}
