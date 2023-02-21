#include "jointcontrolbox.h"
#include "ui_jointcontrolbox.h"


void jointControlBox::MakeJointConnections()
{
	connect(jointBox->plusButton, SIGNAL(clicked()), this, SLOT(PlusButtonPressed()));
	connect(jointBox->minusButton, SIGNAL(clicked()), this, SLOT(MinusButtonPressed()));
}

void jointControlBox::PlusButtonPressed()
{
	emit EmitButtonPressed(POSITIVE_DIRECTION);
}

void jointControlBox::MinusButtonPressed()
{
	emit EmitButtonPressed(NEGATIVE_DIRECTION);
}

