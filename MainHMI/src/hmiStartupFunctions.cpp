#include "mainhmi.h"
#include "./ui_mainhmi.h"

void MainHMI::PerformStartup()
{
    log.WriteLogMessage("Started UI");
    ShowIcon();
    MakeConnections();
    SetConnectionLEDColors();
    JointWidgetsStartup();
    hmi->mainTab->setCurrentIndex(CONTROL_TAB);
    OperationsTabOnStartup();
    ConnectedDeviceState();
    EmergencyButtonColor("red");
    VirtualRobotDefaultState();
    VrDefaultState();
    showMaximized();
    VIRTUAL_ROBOT = false;
    VR4ROBOT_CONNECT = false;
    EMERGENCY_STATE = false;
    WARNING_STATE = false;
    ROBOT_SELECTED = false;
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
    hmi->joint8->PrepareJointControlBoxGraphics();
    hmi->joint9->PrepareJointControlBoxGraphics();
}
