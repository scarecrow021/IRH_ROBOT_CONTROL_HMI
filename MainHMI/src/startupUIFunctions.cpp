#include "mainhmi.h"
#include "./ui_mainhmi.h"

void MainHMI::PerformStartup()
{
    MakeLogFile();
    ShowIcon();
    MakeConnections();
    SetConnectionLEDColors();
    JointWidgetsStartup();
    //SetStyleForComboBoxes();
    showMaximized();
    VIRTUAL_ROBOT = false;
    VR4ROBOT_CONNECT = false;
}


void MainHMI::SetStyleForComboBoxes()
{
    const QString style = "Windows";
    hmi->robotSelector->setStyle(QStyleFactory::create(style));
    hmi->vjMotionSelectX->setStyle(QStyleFactory::create(style));
    hmi->vjMotionSelectY->setStyle(QStyleFactory::create(style));
    hmi->vjMotionSelectZ->setStyle(QStyleFactory::create(style));
    QStringList a = QStyleFactory::keys();
}


void MainHMI::AskForRobotData()
{
	demoRobot.GetRobotData();
}

void MainHMI::ShowIcon()
{
    QPixmap pix("ITER_Logo_NoonYellow.png");
    pix = pix.scaled(hmi->iconLabel->size(), Qt::KeepAspectRatio);
    hmi->iconLabel->setPixmap(pix);
}


void MainHMI::SetConnectionLEDColors()
{
    hmi->vrsLED->setStyleSheet("background-color:silver");
    hmi->vr4robotsLED->setStyleSheet("background-color:silver");
}


void MainHMI::JointWidgetsStartup()
{
    hmi->joint1->PrepareJointControlBoxGraphics();
    hmi->joint2->PrepareJointControlBoxGraphics();
    hmi->joint3->PrepareJointControlBoxGraphics();
    hmi->joint4->PrepareJointControlBoxGraphics();
    hmi->joint5->PrepareJointControlBoxGraphics();
    hmi->joint6->PrepareJointControlBoxGraphics();
    hmi->joint7->PrepareJointControlBoxGraphics();
}
