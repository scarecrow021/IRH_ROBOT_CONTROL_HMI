#ifndef JOINTCONTROLBOX_H
#define JOINTCONTROLBOX_H

#include <QWidget>
#include <mymath.h>

namespace Ui {
class jointControlBox;
}

class jointControlBox : public QWidget
{
    Q_OBJECT

public:
    enum
    {
        NEGATIVE_DIRECTION = -1,
        POSITIVE_DIRECTION = 1
    };
    enum {
        JOINT_STATUS_START,
        JOINT_STATUS_SIMULATOR,
        JOINT_STATUS_READY,
        JOINT_STATUS_EMERGENCY,
        JOINT_STATUS_WARNING,
        JOINT_STATUS_HALT
    };
    explicit jointControlBox(QWidget *parent = nullptr);
    ~jointControlBox();
    void SetGroupBoxTitle(QString text);
    void PrepareJointControlBoxGraphics();
    void SetJointInfoColor(int STATUS);
    void SetJointInfo(std::string min, std::string max, std::string value);
    void SetJointTitle(std::string id, std::string type, std::string unit);
    void MakeJointConnections();
    void ActivateJoint(int STATUS);
    void ActivateJointTargetInput();
    void DisableJointTargetInput();
    double GiveJointTargetValue();
    

public slots:
    void PlusButtonPressed();
    void MinusButtonPressed();

signals:
    void EmitButtonPressed(int direction);


private:
    Ui::jointControlBox *jointBox;
};

#endif // JOINTCONTROLBOX_H
