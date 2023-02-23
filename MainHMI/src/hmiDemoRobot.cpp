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

void MainHMI::SetRobotTitleInfo(int ROBOT_NUMBER)
{
	switch (currentRobotNumberOfJoints)
	{
		{
	case FOUR_JOINTS:
		hmi->joint1->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_1));
		hmi->joint2->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_2));
		hmi->joint3->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_3));
		hmi->joint4->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_4));
		break;

	case FIVE_JOINTS:
		hmi->joint1->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_1));
		hmi->joint2->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_2));
		hmi->joint3->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_3));
		hmi->joint4->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_4));
		hmi->joint5->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_5));
		break;

	case SIX_JOINTS:
		hmi->joint1->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_1));
		hmi->joint2->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_2));
		hmi->joint3->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_3));
		hmi->joint4->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_4));
		hmi->joint5->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_5));
		hmi->joint6->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_6));
		break;

	case SEVEN_JOINTS:
		hmi->joint1->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_1));
		hmi->joint2->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_2));
		hmi->joint3->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_3));
		hmi->joint4->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_4));
		hmi->joint5->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_5));
		hmi->joint6->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_6));
		hmi->joint7->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_7));
		break;

	case EIGHT_JOINTS:
		hmi->joint1->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_1));
		hmi->joint2->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_2));
		hmi->joint3->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_3));
		hmi->joint4->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_4));
		hmi->joint5->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_5));
		hmi->joint6->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_6));
		hmi->joint7->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_7));
		hmi->joint8->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_8));
		break;

	case NINE_JOINTS:
		hmi->joint1->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_1));
		hmi->joint2->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_2));
		hmi->joint3->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_3));
		hmi->joint4->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_4));
		hmi->joint5->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_5));
		hmi->joint6->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_6));
		hmi->joint7->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_7));
		hmi->joint8->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_8));
		hmi->joint9->SetJointTitle(robotContainer.at(ROBOT_NUMBER).PrintJointID(JOINT_9), robotContainer.at(ROBOT_NUMBER).PrintJointType(JOINT_9), robotContainer.at(ROBOT_NUMBER).PrintJointUnit(JOINT_9));
		break;

	default:
		break;
		}
	}
}



void MainHMI::ShowRobotInfo(int ROBOT_NUMBER)
{
	switch (currentRobotNumberOfJoints)
	{
		{
	case FOUR_JOINTS:
		hmi->joint1->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_1));
		hmi->joint2->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_2));
		hmi->joint3->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_3));
		hmi->joint4->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_4));
		break;

	case FIVE_JOINTS:
		hmi->joint1->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_1));
		hmi->joint2->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_2));
		hmi->joint3->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_3));
		hmi->joint4->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_4));
		hmi->joint5->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_5));
		break;

	case SIX_JOINTS:
		hmi->joint1->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_1));
		hmi->joint2->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_2));
		hmi->joint3->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_3));
		hmi->joint4->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_4));
		hmi->joint5->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_5));
		hmi->joint6->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_6));
		break;

	case SEVEN_JOINTS:
		hmi->joint1->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_1));
		hmi->joint2->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_2));
		hmi->joint3->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_3));
		hmi->joint4->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_4));
		hmi->joint5->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_5));
		hmi->joint6->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_6));
		hmi->joint7->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_7));
		break;

	case EIGHT_JOINTS:
		hmi->joint1->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_1));
		hmi->joint2->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_2));
		hmi->joint3->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_3));
		hmi->joint4->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_4));
		hmi->joint5->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_5));
		hmi->joint6->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_6));
		hmi->joint7->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_7));
		hmi->joint8->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_8));
		break;

	case NINE_JOINTS:
		hmi->joint1->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_1), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_1));
		hmi->joint2->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_2), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_2));
		hmi->joint3->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_3), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_3));
		hmi->joint4->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_4), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_4));
		hmi->joint5->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_5), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_5));
		hmi->joint6->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_6), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_6));
		hmi->joint7->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_7), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_7));
		hmi->joint8->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_8), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_8));
		hmi->joint9->SetJointInfo(robotContainer.at(ROBOT_NUMBER).PrintJointMin(JOINT_9), robotContainer.at(ROBOT_NUMBER).PrintJointMax(JOINT_9), robotContainer.at(ROBOT_NUMBER).PrintJointValue(JOINT_9));
		break;

	default:
		break;
		}
	}
}