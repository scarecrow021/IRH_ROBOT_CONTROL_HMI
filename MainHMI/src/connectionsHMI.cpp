#include "mainhmi.h"
#include "./ui_mainhmi.h"

void MainHMI::MakeConnections()
{
	connect(hmi->vrsButton, SIGNAL(pressed()), this, SLOT(vrsLED()));
	connect(hmi->vr4robotsButton, SIGNAL(pressed()), this, SLOT(vr4robotsLED()));
	connect(hmi->setJointTargetButton, SIGNAL(clicked()), this, SLOT(ShowJointTargetBox()));
	connect(hmi->robotSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(RobotSelector(int)));
	connect(hmi->joint1, SIGNAL(EmitButtonPressed(int)), this, SLOT(JointOneUpdateAngle(int)));
	connect(hmi->joint2, SIGNAL(EmitButtonPressed(int)), this, SLOT(JointTwoUpdateAngle(int)));
	connect(hmi->joint3, SIGNAL(EmitButtonPressed(int)), this, SLOT(JointThreeUpdateAngle(int)));
	connect(hmi->joint4, SIGNAL(EmitButtonPressed(int)), this, SLOT(JointFourUpdateAngle(int)));
	connect(hmi->vjMinusX, SIGNAL(clicked()), this, SLOT(vjMinusXClicked()));
	connect(hmi->vjMinusY, SIGNAL(clicked()), this, SLOT(vjMinusYClicked()));
	connect(hmi->vjMinusZ, SIGNAL(clicked()), this, SLOT(vjMinusZClicked()));
	connect(hmi->vjPlusX, SIGNAL(clicked()), this, SLOT(vjPlusXClicked()));
	connect(hmi->vjPlusY, SIGNAL(clicked()), this, SLOT(vjPlusYClicked()));
	connect(hmi->vjPlusZ, SIGNAL(clicked()), this, SLOT(vjPlusZClicked()));
	//connect(hmi->doJointMoveButton, SIGNAL(clicked()), this, SLOT(DoJointMoveButton()));
}




