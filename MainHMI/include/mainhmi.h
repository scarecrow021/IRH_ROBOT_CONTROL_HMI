#ifndef MAINHMI_H
#define MAINHMI_H

#include <QMainWindow>
#include <cppHeaders.h>
#include <ClassDemoRobot.h>
#include <logger.h>
#include <qtHeaders.h>
#include <ClassVirtualSCARA.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainHMI; }
QT_END_NAMESPACE

class MainHMI : public QMainWindow
{
    Q_OBJECT

public:
    double delta = 0.01; // Fix Cartesian Mode Delta
    double deltaTheta = 0.5; // Fix Theta delta
    bool VIRTUAL_ROBOT;
    bool VR4ROBOT_CONNECT;
    enum
    {
        X_AXIS,
        Y_AXIS,
        Z_AXIS
    };
    enum
    {
        NO_ROBOT,
        ROBOT_ONE,
        ROBOT_TWO,
        ROBOT_THREE,
        ROBOT_FOUR
    };
    enum
    {
        NEGATIVE_DIRECTION = -1,
        POSITIVE_DIRECTION = 1
    };
    enum
    {
        JOINT_1,
        JOINT_2,
        JOINT_3,
        JOINT_4,
        JOINT_5,
        JOINT_6,
        JOINT_7
    };
    enum
    {
        TRANSLATION_REQUEST,
        ROTATION_REQUEST
    };
    enum
    {
        FOUR_JOINTS = 4,
        FIVE_JOINTS,
        SIX_JOINTS,
        SEVEN_JOINTS
    };

    int currentRobotNumberOfJoints;
    
    enum { 
        JOINT_STATUS_START,
        JOINT_STATUS_SIMULATOR,
        JOINT_STATUS_READY,
        JOINT_STATUS_EMERGENCY,
        JOINT_STATUS_WARNING,
        JOINT_STATUS_HALT
    };
    MainHMI(QWidget *parent = nullptr);
    ~MainHMI();
    void PerformStartup();
    void AskForRobotData();
    void ShowIcon();
    void CloseEvent(QCloseEvent* event);
    void SetConnectionLEDColors();
    void MakeConnections();
    void JointWidgetsStartup();
    void JointActivation(int STATUS);
    void JointTargetActivation();
    void SetStyleForComboBoxes();
    void UpdateRobotInfo();
    void GenericJointMove(int direction, int jointNum);
    void VirtualJointMove(int axis, int direction);
    


    // Demo Robot Functions
    void ShowDemoRobotInfo();
    void SetDemoRobotTitleInfo();
    void SetDemoRobotEndEffectorPose();


    // Virtual SCARA Trial Functions
    void DefineVirtualSCARARobot();
    void ShowVirtualSCARAInfo();
    void SetVirtualSCARATitleInfo();
    void DebugFunct();
    void SetVirtualSCARAEndEffectorPose();

    enum
    {
        TRANSLATION_AXIS,
        ROTATION_AXIS
    };
    
public slots:
    void vrsLED();
    void vr4robotsLED();
    void ShowJointTargetBox();
    void RobotSelector(int index);
    void JointOneUpdateAngle(int direction);
    void JointTwoUpdateAngle(int direction);
    void JointThreeUpdateAngle(int direction);
    void JointFourUpdateAngle(int direction);
    void vjPlusXClicked();
    void vjPlusYClicked();
    void vjPlusZClicked();
    void vjMinusXClicked();
    void vjMinusYClicked();
    void vjMinusZClicked();
    //void DoJointMoveButton();
    


private:
    Ui::MainHMI *hmi;
    DemoRobot demoRobot;
    VirtualSCARA scara;
    
};
#endif // MAINHMI_H
