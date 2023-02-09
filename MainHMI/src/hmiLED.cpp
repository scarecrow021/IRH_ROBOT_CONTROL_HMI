#include "mainhmi.h"
#include "./ui_mainhmi.h"



void MainHMI::vrsLED()
{
	if (!hmi->vrsButton->isChecked())
	{
		hmi->vrsLED->setStyleSheet("background-color:lime");
		VIRTUAL_ROBOT = true;
		VR4ROBOT_CONNECT = false;
	}
	else
	{
		hmi->vrsLED->setStyleSheet("background-color:silver");
		VIRTUAL_ROBOT = false;
		VR4ROBOT_CONNECT = false;
	}
}

void MainHMI::vr4robotsLED()
{
	if (!hmi->vr4robotsButton->isChecked())
	{
		hmi->vr4robotsLED->setStyleSheet("background-color:lime");
		VR4ROBOT_CONNECT = true;
		VIRTUAL_ROBOT = false;
		demoRobot.GetRobotData();
		currentRobotNumberOfJoints = demoRobot.joints.size();
		hmi->robotSelector->addItem(demoRobot.PrintRobotName().c_str());

	}
	else
	{
		hmi->vr4robotsLED->setStyleSheet("background-color:silver");
		VR4ROBOT_CONNECT = false;
		VIRTUAL_ROBOT = false;
	}
}



