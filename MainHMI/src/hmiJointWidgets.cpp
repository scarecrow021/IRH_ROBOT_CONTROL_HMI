#include "mainhmi.h"
#include "./ui_mainhmi.h"

void MainHMI::JointActivation(int STATUS)
{
	switch (currentRobotNumberOfJoints)
	{
	case FOUR_JOINTS:
		hmi->joint1->ActivateJoint(STATUS);
		hmi->joint2->ActivateJoint(STATUS);
		hmi->joint3->ActivateJoint(STATUS);
		hmi->joint4->ActivateJoint(STATUS);
		break;

	case FIVE_JOINTS:
		hmi->joint1->ActivateJoint(STATUS);
		hmi->joint2->ActivateJoint(STATUS);
		hmi->joint3->ActivateJoint(STATUS);
		hmi->joint4->ActivateJoint(STATUS);
		hmi->joint5->ActivateJoint(STATUS);
		break;

	case SIX_JOINTS:
		hmi->joint1->ActivateJoint(STATUS);
		hmi->joint2->ActivateJoint(STATUS);
		hmi->joint3->ActivateJoint(STATUS);
		hmi->joint4->ActivateJoint(STATUS);
		hmi->joint5->ActivateJoint(STATUS);
		hmi->joint6->ActivateJoint(STATUS);
		break;

	case SEVEN_JOINTS:
		hmi->joint1->ActivateJoint(STATUS);
		hmi->joint2->ActivateJoint(STATUS);
		hmi->joint3->ActivateJoint(STATUS);
		hmi->joint4->ActivateJoint(STATUS);
		hmi->joint5->ActivateJoint(STATUS);
		hmi->joint6->ActivateJoint(STATUS);
		hmi->joint7->ActivateJoint(STATUS);
		break;

	default:
		break;
	}
	
}

void MainHMI::JointTargetActivation()
{
	switch (currentRobotNumberOfJoints)
	{
	case FOUR_JOINTS:
		hmi->joint1->ActivateJointTargetInput();
		hmi->joint2->ActivateJointTargetInput();
		hmi->joint3->ActivateJointTargetInput();
		hmi->joint4->ActivateJointTargetInput();
		break;

	case FIVE_JOINTS:
		hmi->joint1->ActivateJointTargetInput();
		hmi->joint2->ActivateJointTargetInput();
		hmi->joint3->ActivateJointTargetInput();
		hmi->joint4->ActivateJointTargetInput();
		hmi->joint5->ActivateJointTargetInput();
		break;

	case SIX_JOINTS:
		hmi->joint1->ActivateJointTargetInput();
		hmi->joint2->ActivateJointTargetInput();
		hmi->joint3->ActivateJointTargetInput();
		hmi->joint4->ActivateJointTargetInput();
		hmi->joint5->ActivateJointTargetInput();
		hmi->joint6->ActivateJointTargetInput();
		break;

	case SEVEN_JOINTS:
		hmi->joint1->ActivateJointTargetInput();
		hmi->joint2->ActivateJointTargetInput();
		hmi->joint3->ActivateJointTargetInput();
		hmi->joint4->ActivateJointTargetInput();
		hmi->joint5->ActivateJointTargetInput();
		hmi->joint6->ActivateJointTargetInput();
		hmi->joint7->ActivateJointTargetInput();
		break;

	default:
		break;
	}

}


void MainHMI::JointOneUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_1);
}

void MainHMI::JointTwoUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_2);
}

void MainHMI::JointThreeUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_3);
}

void MainHMI::JointFourUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_4);
}

void MainHMI::GenericJointMove(int direction, int jointNum)
{
	switch (hmi->robotSelector->currentIndex())
	{
	case NO_ROBOT:
		break;

	case ROBOT_ONE:
		scara.UpdateJoint(jointNum, direction * hmi->translationStepBox->value(), direction * hmi->rotationStepBox->value());
		UpdateRobotInfo();
		break;

	case ROBOT_TWO:
		demoRobot.UpdateJoint(jointNum, direction * hmi->translationStepBox->value(), direction * hmi->rotationStepBox->value());
		demoRobot.MoveRobot();
		UpdateRobotInfo();
		break;

	default:
		break;
	}
}

void MainHMI::UpdateRobotInfo()
{
	switch (hmi->robotSelector->currentIndex())
	{
	case NO_ROBOT:
		JointWidgetsStartup();
		break;

	case ROBOT_ONE:
		//SetVirtualSCARATitleInfo();
		ShowVirtualSCARAInfo();
		SetVirtualSCARAEndEffectorPose();
		break;

	case ROBOT_TWO:
		ShowDemoRobotInfo();
		SetDemoRobotEndEffectorPose();
		break;

	default:
		break;
	}
}


void MainHMI::ShowJointTargetBox()
{
	if (hmi->robotSelector->currentIndex() != NO_ROBOT)
	{
		JointTargetActivation();
	}
}


/*
void MainHMI::DoJointMoveButton()
{
	switch (hmi->robotSelector->currentIndex())
	{
	case NO_ROBOT:
		//nothing
		break;

	case ROBOT_ONE:
		// will do later
		break;

	case ROBOT_TWO:
		double j[4];
		j[0] = hmi->joint1->GiveJointTargetValue();
		j[1] = hmi->joint2->GiveJointTargetValue();
		j[2] = hmi->joint3->GiveJointTargetValue();
		j[3] = hmi->joint4->GiveJointTargetValue();
		demoRobot.SetJointTarget(j);
		UpdateRobotInfo();
		break;

	default:
		break;
	}
}

*/
