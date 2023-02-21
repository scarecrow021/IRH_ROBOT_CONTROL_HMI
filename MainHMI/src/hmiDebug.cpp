#include "mainhmi.h"
#include "./ui_mainhmi.h"


// Virtual Robot Simulator Initial Robot Definitions

void MainHMI::DebugFunct()
{
	DefineVirtualSCARARobot();
}


void MainHMI::DefineVirtualSCARARobot()
{
	if (scara.joints.size() > 1)
	{
		scara.Restart();
	}
	scara.SetLengths(0.8,0.6,0.425);
	scara.AddJoint("joint_One", "rotational", 30.0, -270.0, 270.0);
	scara.AddJoint("joint_Two", "rotational", 60.0, -270.0, 270.0);
	scara.AddJoint("joint_Three", "rotational", 90.0, -270.0, 270.0);
	scara.AddJoint("joint_Four", "translational", 0.0, 0.0, 0.5);
	scara.CalculateCurrentPoint();
	currentRobotNumberOfJoints = scara.joints.size();
	SetVirtualSCARATitleInfo();
	ShowVirtualSCARAInfo();
	SetVirtualSCARAEndEffectorPose();
	JointActivation(JOINT_STATUS_SIMULATOR);
	hmi->translationStepBox->setValue(0.05);
	hmi->rotationStepBox->setValue(10);
}

void MainHMI::ShowVirtualSCARAInfo()
{
	hmi->joint1->SetJointInfo(scara.PrintJointMin(JOINT_1), scara.PrintJointMax(JOINT_1), scara.PrintJointValue(JOINT_1));
	hmi->joint2->SetJointInfo(scara.PrintJointMin(JOINT_2), scara.PrintJointMax(JOINT_2), scara.PrintJointValue(JOINT_2));
	hmi->joint3->SetJointInfo(scara.PrintJointMin(JOINT_3), scara.PrintJointMax(JOINT_3), scara.PrintJointValue(JOINT_3));
	hmi->joint4->SetJointInfo(scara.PrintJointMin(JOINT_4), scara.PrintJointMax(JOINT_4), scara.PrintJointValue(JOINT_4));
}

void MainHMI::SetVirtualSCARATitleInfo()
{
	hmi->joint1->SetJointTitle(scara.PrintJointID(JOINT_1), scara.PrintJointType(JOINT_1), scara.PrintJointUnit(JOINT_1));
	hmi->joint2->SetJointTitle(scara.PrintJointID(JOINT_2), scara.PrintJointType(JOINT_2), scara.PrintJointUnit(JOINT_2));
	hmi->joint3->SetJointTitle(scara.PrintJointID(JOINT_3), scara.PrintJointType(JOINT_3), scara.PrintJointUnit(JOINT_3));
	hmi->joint4->SetJointTitle(scara.PrintJointID(JOINT_4), scara.PrintJointType(JOINT_4), scara.PrintJointUnit(JOINT_4));
}

void MainHMI::SetVirtualSCARAEndEffectorPose()
{
	scara.CalculateCurrentPoint();
	hmi->eeTransX->setValue(scara.currentPoint.x);
	hmi->eeTransY->setValue(scara.currentPoint.y);
	hmi->eeTransZ->setValue(scara.currentPoint.z);
	hmi->eeRotZ->setValue(scara.currentTheta);
	hmi->eeRotX->setHidden(true);
	hmi->eeRotY->setHidden(true);
}

