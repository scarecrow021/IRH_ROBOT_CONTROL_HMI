#include "mainhmi.h"
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
    CloseLogFile();
    QWidget::closeEvent(event);
}


void MainHMI::RobotSelector(int index)
{

	switch (hmi->robotSelector->currentIndex())
	{
	case NO_ROBOT:
		JointWidgetsStartup();
		break;

	case ROBOT_ONE:
		if (VIRTUAL_ROBOT)
		{
			DebugFunct();
			break;
		}
		else
		{
			break;
		}
		break;

	case ROBOT_TWO:
		if (VR4ROBOT_CONNECT)
		{
			JointActivation(JOINT_STATUS_READY);
			hmi->translationStepBox->setValue(0.05);
			hmi->rotationStepBox->setValue(10);
			ShowDemoRobotInfo();
			SetDemoRobotTitleInfo();
			SetDemoRobotEndEffectorPose();
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


