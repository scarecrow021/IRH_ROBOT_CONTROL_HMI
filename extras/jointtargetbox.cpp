#include "jointtargetbox.h"
#include "./ui_jointtargetbox.h"

jointTargetBox::jointTargetBox(QWidget *parent)
    : QMainWindow(parent)
    , jointTargetBoxUI(new Ui::jointTargetBox)
{
    jointTargetBoxUI->setupUi(this);
}

jointTargetBox::~jointTargetBox()
{
    delete jointTargetBoxUI;
}

