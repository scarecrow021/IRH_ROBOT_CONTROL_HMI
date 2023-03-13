#ifndef JOINTCONTROLBOX_H
#define JOINTCONTROLBOX_H

#include <qtHeaders.hpp>
#include <mymath.hpp>
#include <flags.hpp>

namespace Ui {
class jointControlBox;
}

class jointControlBox : public QWidget
{
    Q_OBJECT

public:
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
