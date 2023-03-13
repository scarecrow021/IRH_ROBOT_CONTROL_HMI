#ifndef MAINHMI_H
#define MAINHMI_H

#include <qtHeaders.hpp>
#include <cppHeaders.hpp>
#include <ClassDemoRobot.hpp>
#include <logger.hpp>
#include <ClassVirtualSCARA.hpp>
#include <flags.hpp>
#include <GetRobotData.hpp>


QT_BEGIN_NAMESPACE
namespace Ui { class MainHMI; }
QT_END_NAMESPACE

class MainHMI : public QMainWindow
{
    Q_OBJECT

public:
    double delta = 0.01; // Fix Cartesian Mode Delta
    double deltaTheta = 0.5; // Fix Theta delta
    int currentConnection;
    int currentRobotNumberOfJoints;

    // some internal flags
    bool VIRTUAL_ROBOT;
    bool VR4ROBOT_CONNECT;
    bool EMERGENCY_STATE;
    bool WARNING_STATE;
    bool ROBOT_SELECTED;
    
    // Functions Below

    MainHMI(QWidget *parent = nullptr);
    ~MainHMI();

    // Startup Functions

    void PerformStartup();
    void ShowIcon();
    void SetConnectionLEDColors();
    void MakeConnections();
    void SetInitialRobotList();
    void JointWidgetsStartup();
    void JointStatusColorDisplay(int STATUS);
    void JointTargetActivation();
    void UpdateRobotInfo();
    void GenericJointMove(int direction, int jointNum);
    void VirtualJointMove(int axis, int direction);
    void DisableAllJointTargets();
    void OperationsTabOnStartup();
    
    
    void EmergencyButtonColor(QString color);
    
    
    

    // State Functions

    void ConnectedDeviceState();
    void VirtualRobotDefaultState();
    void VirtualRobotConnectState(bool state);
    void VirtualRobotReadyState(bool state);
    void VirtualRobotStopState(bool state);
    void VrDefaultState();
    void VrConnectState(bool state);
    void VrReadyState(bool state);
    void VrWarningState(bool state);
    void VrStopState(bool state);
    void WarningStateDisplay();


    // Demo Robot Functions

    void ShowDemoRobotInfo();
    void SetDemoRobotTitleInfo();
    void SetDemoRobotEndEffectorPose();


    // Virtual SCARA Trial Functions

    void DefineVirtualSCARARobot();
    void ShowVirtualSCARAInfo();
    void SetVirtualSCARATitleInfo();
    void SetVirtualSCARAEndEffectorPose();

    // General Robot Functions
    void AddRobotsToHMI();
    void ShowRobotInfo(int ROBOT_NUMBER);
    void SetRobotTitleInfo(int ROBOT_NUMBER);
    void EmptyRobotContainer();

    // Closing Function

    void CloseEvent(QCloseEvent* event);

    
    

    // Slots 

public slots:
    void vrsLED();
    void vr4robotsLED();
    void ShowJointTargetBox();
    void RobotSelector(int index);
    void JointOneUpdateAngle(int direction);
    void JointTwoUpdateAngle(int direction);
    void JointThreeUpdateAngle(int direction);
    void JointFourUpdateAngle(int direction);
    void JointFiveUpdateAngle(int direction);
    void JointSixUpdateAngle(int direction);
    void JointSevenUpdateAngle(int direction);
    void JointEightUpdateAngle(int direction);
    void JointNineUpdateAngle(int direction);
    void vjPlusXClicked();
    void vjPlusYClicked();
    void vjPlusZClicked();
    void vjMinusXClicked();
    void vjMinusYClicked();
    void vjMinusZClicked();
    void DoJointMoveButton();
    void EmergencyStopButton();
    void DebugFunct();
    
    


private:
    Ui::MainHMI *hmi;
    Logger log;
    DemoRobot demoRobot;
    std::vector<Robot> robotContainer;
    VirtualSCARA scara;
    
};
#endif // MAINHMI_H
