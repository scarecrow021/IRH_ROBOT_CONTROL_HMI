#include "mainhmi.h"
#include "./ui_mainhmi.h"


void MainHMI::OperationsTabOnStartup()
{
	hmi->pointFileFrame->setDisabled(true);
	hmi->jointConfigFileFrame->setDisabled(true);
	
}