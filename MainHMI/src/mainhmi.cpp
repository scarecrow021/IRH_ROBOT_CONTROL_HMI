#include <mainhmi.h>
#include "./ui_mainhmi.h"


MainHMI::MainHMI(QWidget *parent)
    : QMainWindow(parent)
    , hmi(new Ui::MainHMI)
{
    hmi->setupUi(this);
    this->setWindowTitle("ITER RH Robot Control HMI");
}

MainHMI::~MainHMI()
{
    delete hmi;
}

void MainHMI::CloseEvent(QCloseEvent* event)
{
	log.~Logger();
    QWidget::closeEvent(event);
}


void MainHMI::RobotSelector(int index)
{

	switch (hmi->robotSelector->currentIndex())
	{
	case (NO_ROBOT+2):
		JointWidgetsStartup();
		ROBOT_SELECTED = false;
		VirtualRobotReadyState(false);
		VrReadyState(false);
		break;

	case (VIRTUAL_SCARA+2):
		if (VIRTUAL_ROBOT && !VR4ROBOT_CONNECT)
		{
			DefineVirtualSCARARobot();
			ROBOT_SELECTED = true;
			VirtualRobotReadyState(true);
			break;
		}
		else
		{
			break;
		}
		break;

	case (ROBOT_ONE+2):
		if (VR4ROBOT_CONNECT && !VIRTUAL_ROBOT)
		{
			currentRobotNumberOfJoints = robotContainer.at(ROBOT_ONE).numberOfJoints;
			JointStatusColorDisplay(JOINT_STATUS_READY);
			hmi->translationStepBox->setValue(0.05);
			hmi->rotationStepBox->setValue(10);
			ShowRobotInfo(ROBOT_ONE);
			SetRobotTitleInfo(ROBOT_ONE);
			ROBOT_SELECTED = true;
			VrReadyState(true);
			
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
			JointStatusColorDisplay(JOINT_STATUS_READY);
			hmi->translationStepBox->setValue(0.05);
			hmi->rotationStepBox->setValue(10);
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


void MainHMI::AddRobotsToHMI()
{
	// Since at this moment, we are only expecting Demo Robot
	robotContainer = GetRobotData();
	//currentRobotNumberOfJoints = demoRobot.joints.size();
	for (int i = 0; i < robotContainer.size(); i++)
	{
		hmi->robotSelector->addItem(robotContainer.at(i).PrintRobotName().c_str());
	}
	
}





void MainHMI::EmptyRobotContainer()
{
	if (robotContainer.size() > 0)
	{
		robotContainer.clear();
		SetInitialRobotList();
	}
	else
	{
		std::cout << "nothing to clear";
	}
}




void MainHMI::EmergencyStopButton()
{
	if (ROBOT_SELECTED)
	{
		if (VIRTUAL_ROBOT)
		{
			if (!EMERGENCY_STATE)
			{
				EMERGENCY_STATE = true;
				VirtualRobotStopState(true);
				VirtualRobotReadyState(false);
				JointStatusColorDisplay(JOINT_STATUS_EMERGENCY);
				EmergencyButtonColor("green");
			}
			else if (EMERGENCY_STATE)
			{
				EMERGENCY_STATE = false;
				JointStatusColorDisplay(JOINT_STATUS_SIMULATOR);
				EmergencyButtonColor("red");
				VirtualRobotStopState(false);
				VirtualRobotReadyState(true);
			}
		}
		else if (VR4ROBOT_CONNECT)
		{
			if (!EMERGENCY_STATE)
			{
				EMERGENCY_STATE = true;
				VrStopState(true);
				VrReadyState(false);
				JointStatusColorDisplay(JOINT_STATUS_EMERGENCY);
				EmergencyButtonColor("green");
			}
			else if (EMERGENCY_STATE)
			{
				EMERGENCY_STATE = false;
				JointStatusColorDisplay(JOINT_STATUS_SIMULATOR);
				EmergencyButtonColor("red");
				VrStopState(false);
				VrReadyState(true);
			}
		}
	}
	
	// else nothing to do, no robot is connected...
}



void MainHMI::WarningStateDisplay()
{
	
	if (ROBOT_SELECTED)
	{
		// no warning state for virtual robot
		if (VR4ROBOT_CONNECT)
		{
			if (!WARNING_STATE)
			{
				WARNING_STATE = true;
				VrWarningState(true);
				JointStatusColorDisplay(JOINT_STATUS_WARNING);
			}
			else if (WARNING_STATE)
			{
				WARNING_STATE = false;
				JointStatusColorDisplay(JOINT_STATUS_SIMULATOR);
				VrWarningState(false);
			}
		}
	}
}


void MainHMI::EmergencyButtonColor(QString color)
{
	if (color == "red")
	{
		const QString redButton = "QPushButton{color: black;border: 2px solid rgb(0, 0, 0);border - radius: 20px;border - style: outset; background: qradialgradient(cx : 0.3, cy : -0.3, fx : -0.4, fy : 0.4, radius : 1.2,stop : 0 rgb(250, 0, 0),stop : 1 rgb(253, 80, 122));padding: 5px;} QPushButton:hover{background: qradialgradient(cx : 0.3, cy : -0.3, fx : -0.4, fy : 0.4,radius : 1.1, stop : 0 rgb(250,0,0), stop : 1 rgb(247,23,83));} QPushButton:pressed{border: 5px solid rgb(20,20,20);background: qradialgradient(cx : -0.3, cy : 0.3, fx : 0.4, fy : -0.4,radius : 1.3, stop : 0 rgb(250,0,0), stop : 1 rgb(250,250,250));}";
		hmi->emergencyStopButton->setStyleSheet(redButton);
		hmi->emergencyStopButton->setText("STOP");
	}
	else if (color == "green")
	{
		const QString greenButton = "QPushButton{color: black;border: 2px solid rgb(0, 0, 0);border - radius: 20px;border - style: outset; background: qradialgradient(cx : 0.3, cy : -0.3, fx : -0.4, fy : 0.4, radius : 1.2,stop : 0 rgb(0, 250, 0),stop : 1 rgb(80, 253, 122));padding: 5px;} QPushButton:hover{background: qradialgradient(cx : 0.3, cy : -0.3, fx : -0.4, fy : 0.4,radius : 1.1, stop : 0 rgb(0,250,0), stop : 1 rgb(23,247,83));} QPushButton:pressed{border: 5px solid rgb(20,20,20);background: qradialgradient(cx : -0.3, cy : 0.3, fx : 0.4, fy : -0.4,radius : 1.3, stop : 0 rgb(0,250,0), stop : 1 rgb(250,250,250));}";
		hmi->emergencyStopButton->setStyleSheet(greenButton);
		hmi->emergencyStopButton->setText("START");
	}
}