#include "mainhmi.h"
#include "./ui_mainhmi.h"


// Let's make device state functions
// These are not slots.

void MainHMI::ConnectedDeviceState()
{
	// HMI is always on on start up.
	// No need to do something special
	hmi->hmiConnectedDevicesStates->setStyleSheet("background-color:lime");
}


void MainHMI::VirtualRobotDefaultState()
{
	VirtualRobotConnectState(false);
	VirtualRobotReadyState(false);
	VirtualRobotStopState(false);
}


void MainHMI::VirtualRobotConnectState(bool state)
{
	if (state == true)
	{
		hmi->virtualState->setStyleSheet("background-color:lime");
	}
	else
	{
		hmi->virtualState->setStyleSheet("background-color:grey");
	}
}

void MainHMI::VirtualRobotReadyState(bool state)
{
	if (state == true)
	{
		hmi->virtualReadyState->setStyleSheet("background-color:lime");
	}
	else
	{
		hmi->virtualReadyState->setStyleSheet("background-color:grey");
	}
}

void MainHMI::VirtualRobotStopState(bool state)
{
	if (state == true)
	{
		hmi->virtualStopState->setStyleSheet("background-color:red");
	}
	else
	{
		hmi->virtualStopState->setStyleSheet("background-color:grey");
	}
}

void MainHMI::VrDefaultState()
{
	VrConnectState(false);
	VrReadyState(false);
	VrWarningState(false);
	VrStopState(false);
}

void MainHMI::VrConnectState(bool state)
{
	if (state == true)
	{
		hmi->vr4State->setStyleSheet("background-color:lime");
	}
	else
	{
		hmi->vr4State->setStyleSheet("background-color:grey");
	}
}

void MainHMI::VrReadyState(bool state)
{
	if (state == true)
	{
		hmi->vr4ReadyState->setStyleSheet("background-color:lime");
	}
	else
	{
		hmi->vr4ReadyState->setStyleSheet("background-color:grey");
	}
}

void MainHMI::VrWarningState(bool state)
{
	if (state == true)
	{
		hmi->vr4WarningState->setStyleSheet("background-color:orange");
	}
	else
	{
		hmi->vr4WarningState->setStyleSheet("background-color:grey");
	}
}

void MainHMI::VrStopState(bool state)
{
	if (state == true)
	{
		hmi->vr4StopState->setStyleSheet("background-color:red");
	}
	else
	{
		hmi->vr4StopState->setStyleSheet("background-color:grey");
	}
}