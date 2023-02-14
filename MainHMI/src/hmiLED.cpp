#include "mainhmi.h"
#include "./ui_mainhmi.h"



void MainHMI::vrsLED()
{
	if (!hmi->vrsButton->isChecked())
	{
		hmi->vrsLED->setStyleSheet("background-color:lime");
		VIRTUAL_ROBOT = true;
		VR4ROBOT_CONNECT = false;


		int controllerId = -1;
		std::cout << "going to read controllers" << std::endl;
		for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
		{
			std::cout << "inside for loop" << std::endl;
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));

			if (XInputGetState(i, &state) == ERROR_SUCCESS)
			{
				controllerId = i;
				std::cout << "controller_found ID :  " << controllerId << std::endl;
				bool A_button_pressed = ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A) != 0);
				std::cout << "A button : " << A_button_pressed << std::endl;
				float leftTrigger = (float)state.Gamepad.bLeftTrigger / 255;
				std::cout << "left trigger : " << leftTrigger << std::endl;
			}
		}


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



