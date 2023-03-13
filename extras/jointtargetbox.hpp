#ifndef JOINTTARGETBOX_H
#define JOINTTARGETBOX_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class jointTargetBox; }
QT_END_NAMESPACE

class jointTargetBox : public QMainWindow
{
    Q_OBJECT

public:
    jointTargetBox(QWidget *parent = nullptr);
    ~jointTargetBox();
    Ui::jointTargetBox *jointTargetBoxUI;
};
#endif // JOINTTARGETBOX_H
