#include "mainhmi.h"
#include "./ui_mainhmi.h"

void MainHMI::JointStatusColorDisplay(int STATUS)
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

	case EIGHT_JOINTS:
		hmi->joint1->ActivateJoint(STATUS);
		hmi->joint2->ActivateJoint(STATUS);
		hmi->joint3->ActivateJoint(STATUS);
		hmi->joint4->ActivateJoint(STATUS);
		hmi->joint5->ActivateJoint(STATUS);
		hmi->joint6->ActivateJoint(STATUS);
		hmi->joint7->ActivateJoint(STATUS);
		hmi->joint8->ActivateJoint(STATUS);
		break;

	case NINE_JOINTS:
		hmi->joint1->ActivateJoint(STATUS);
		hmi->joint2->ActivateJoint(STATUS);
		hmi->joint3->ActivateJoint(STATUS);
		hmi->joint4->ActivateJoint(STATUS);
		hmi->joint5->ActivateJoint(STATUS);
		hmi->joint6->ActivateJoint(STATUS);
		hmi->joint7->ActivateJoint(STATUS);
		hmi->joint8->ActivateJoint(STATUS);
		hmi->joint9->ActivateJoint(STATUS);
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

	case EIGHT_JOINTS:
		hmi->joint1->ActivateJointTargetInput();
		hmi->joint2->ActivateJointTargetInput();
		hmi->joint3->ActivateJointTargetInput();
		hmi->joint4->ActivateJointTargetInput();
		hmi->joint5->ActivateJointTargetInput();
		hmi->joint6->ActivateJointTargetInput();
		hmi->joint7->ActivateJointTargetInput();
		hmi->joint8->ActivateJointTargetInput();
		break;

	case NINE_JOINTS:
		hmi->joint1->ActivateJointTargetInput();
		hmi->joint2->ActivateJointTargetInput();
		hmi->joint3->ActivateJointTargetInput();
		hmi->joint4->ActivateJointTargetInput();
		hmi->joint5->ActivateJointTargetInput();
		hmi->joint6->ActivateJointTargetInput();
		hmi->joint7->ActivateJointTargetInput();
		hmi->joint8->ActivateJointTargetInput();
		hmi->joint9->ActivateJointTargetInput();
		break;

	default:
		break;
	}

}


void MainHMI::DisableAllJointTargets()
{
	switch (currentRobotNumberOfJoints)
	{
	case FOUR_JOINTS:
		hmi->joint1->DisableJointTargetInput();
		hmi->joint2->DisableJointTargetInput();
		hmi->joint3->DisableJointTargetInput();
		hmi->joint4->DisableJointTargetInput();
		break;

	case FIVE_JOINTS:
		hmi->joint1->DisableJointTargetInput();
		hmi->joint2->DisableJointTargetInput();
		hmi->joint3->DisableJointTargetInput();
		hmi->joint4->DisableJointTargetInput();
		hmi->joint5->DisableJointTargetInput();
		break;

	case SIX_JOINTS:
		hmi->joint1->DisableJointTargetInput();
		hmi->joint2->DisableJointTargetInput();
		hmi->joint3->DisableJointTargetInput();
		hmi->joint4->DisableJointTargetInput();
		hmi->joint5->DisableJointTargetInput();
		hmi->joint6->DisableJointTargetInput();
		break;

	case SEVEN_JOINTS:
		hmi->joint1->DisableJointTargetInput();
		hmi->joint2->DisableJointTargetInput();
		hmi->joint3->DisableJointTargetInput();
		hmi->joint4->DisableJointTargetInput();
		hmi->joint5->DisableJointTargetInput();
		hmi->joint6->DisableJointTargetInput();
		hmi->joint7->DisableJointTargetInput();
		break;

	case EIGHT_JOINTS:
		hmi->joint1->DisableJointTargetInput();
		hmi->joint2->DisableJointTargetInput();
		hmi->joint3->DisableJointTargetInput();
		hmi->joint4->DisableJointTargetInput();
		hmi->joint5->DisableJointTargetInput();
		hmi->joint6->DisableJointTargetInput();
		hmi->joint7->DisableJointTargetInput();
		hmi->joint8->DisableJointTargetInput();
		break;

	case NINE_JOINTS:
		hmi->joint1->DisableJointTargetInput();
		hmi->joint2->DisableJointTargetInput();
		hmi->joint3->DisableJointTargetInput();
		hmi->joint4->DisableJointTargetInput();
		hmi->joint5->DisableJointTargetInput();
		hmi->joint6->DisableJointTargetInput();
		hmi->joint7->DisableJointTargetInput();
		hmi->joint8->DisableJointTargetInput();
		hmi->joint9->DisableJointTargetInput();
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

void MainHMI::JointFiveUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_5);
}

void MainHMI::JointSixUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_6);
}

void MainHMI::JointSevenUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_7);
}

void MainHMI::JointEightUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_8);
}

void MainHMI::JointNineUpdateAngle(int direction)
{
	GenericJointMove(direction, JOINT_9);
}


void MainHMI::GenericJointMove(int direction, int jointNum)
{
	switch (hmi->robotSelector->currentIndex())
	{
	case (NO_ROBOT + 2):
		break;

	case (VIRTUAL_SCARA + 2):
		scara.UpdateJoint(jointNum, direction * hmi->translationStepBox->value(), direction * hmi->rotationStepBox->value());
		UpdateRobotInfo();
		break;

	case (ROBOT_ONE + 2):
		robotContainer.at(ROBOT_ONE).UpdateJoint(jointNum, direction * hmi->translationStepBox->value(), direction * hmi->rotationStepBox->value());
		robotContainer.at(ROBOT_ONE).MoveRobot();
		UpdateRobotInfo();
		break;

	case (ROBOT_TWO + 2):
		robotContainer.at(ROBOT_TWO).UpdateJoint(jointNum, direction * hmi->translationStepBox->value(), direction * hmi->rotationStepBox->value());
		robotContainer.at(ROBOT_TWO).MoveRobot();
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
	case (NO_ROBOT + 2):
		JointWidgetsStartup();
		break;

	case (VIRTUAL_SCARA + 2):
		if (VIRTUAL_ROBOT && !VR4ROBOT_CONNECT)
		{
			ShowVirtualSCARAInfo();
			SetVirtualSCARAEndEffectorPose();
			break;
		}
		else
		{
			break;
		}
		break;

	case (ROBOT_ONE + 2):
		if (VR4ROBOT_CONNECT && !VIRTUAL_ROBOT)
		{
			currentRobotNumberOfJoints = robotContainer.at(ROBOT_ONE).numberOfJoints;
			ShowRobotInfo(ROBOT_ONE);
			SetRobotTitleInfo(ROBOT_ONE);
			break;
		}
		else
		{
			break;
		}
		break;

	case (ROBOT_TWO + 2):
		if (VR4ROBOT_CONNECT && !VIRTUAL_ROBOT)
		{
			currentRobotNumberOfJoints = robotContainer.at(ROBOT_TWO).numberOfJoints;
			ShowRobotInfo(ROBOT_TWO);
			SetRobotTitleInfo(ROBOT_TWO);
			ROBOT_SELECTED = true;
			VrReadyState(true);

			break;
		}
		else
		{
			break;
		}
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
		DisableAllJointTargets();
		break;

	default:
		break;
	}
}

