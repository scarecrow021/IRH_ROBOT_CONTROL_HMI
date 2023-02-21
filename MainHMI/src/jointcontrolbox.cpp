#include "jointcontrolbox.h"
#include "ui_jointcontrolbox.h"

jointControlBox::jointControlBox(QWidget *parent) :
    QWidget(parent),
    jointBox(new Ui::jointControlBox)
{
    jointBox->setupUi(this);
    MakeJointConnections();
}

jointControlBox::~jointControlBox()
{
    delete jointBox;
}

void jointControlBox::SetGroupBoxTitle(QString text)
{
    jointBox->jointInfoBox->setTitle(text);
}

void jointControlBox::PrepareJointControlBoxGraphics()
{
    jointBox->jointCurrent->setDisabled(true);
    jointBox->jointMax->setDisabled(true);
    jointBox->jointMin->setDisabled(true);
    jointBox->jointTarget->setDisabled(true);
    jointBox->minusButton->setDisabled(true);
    jointBox->plusButton->setDisabled(true);
    SetJointInfoColor(JOINT_STATUS_START);
    jointBox->jointCurrent->setText("Now");
    jointBox->jointMax->setText("Max");
    jointBox->jointMin->setText("Min");
}



void jointControlBox::SetJointInfoColor(int STATUS)
{
    if (STATUS == JOINT_STATUS_START)
    {
        jointBox->jointInfoBox->setStyleSheet("background-color: rgba(173, 173, 173, 20)");
    }
    else if (STATUS == JOINT_STATUS_SIMULATOR)
    {
        jointBox->jointInfoBox->setStyleSheet("background-color: rgba(255, 153, 250, 80)");
    }
    else if (STATUS == JOINT_STATUS_READY)
    {
        jointBox->jointInfoBox->setStyleSheet("background-color: rgba(17, 255, 0, 80)");
    }
}

void jointControlBox::SetJointInfo(std::string min, std::string max, std::string value)
{
    jointBox->jointMin->setText(min.c_str());
    jointBox->jointMax->setText(max.c_str());
    jointBox->jointCurrent->setText(value.c_str());
    jointBox->jointTarget->setValue(std::stod(value));
}

void jointControlBox::SetJointTitle(std::string id, std::string type, std::string unit)
{
    std::string titleText = id + " - " + type + " - " + unit;
    jointBox->jointInfoBox->setTitle(titleText.c_str());
}

void jointControlBox::ActivateJoint(int STATUS)
{
    jointBox->jointCurrent->setEnabled(true);
    jointBox->jointMax->setEnabled(true);
    jointBox->jointMin->setEnabled(true);
    jointBox->minusButton->setEnabled(true);
    jointBox->plusButton->setEnabled(true);
    jointBox->jointTarget->setDisabled(true);
    SetJointInfoColor(STATUS);
}

void jointControlBox::ActivateJointTargetInput()
{
    jointBox->jointTarget->setEnabled(true);
}


double jointControlBox::GiveJointTargetValue()
{
    return jointBox->jointTarget->value();
}



void jointControlBox::DisableJointTargetInput()
{
    jointBox->jointTarget->setDisabled(true);
}
