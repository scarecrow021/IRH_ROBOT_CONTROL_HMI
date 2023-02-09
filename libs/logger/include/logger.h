/**
*	\file		logger
*	\brief		logger container for making log files
*	\author		Soumik SARKAR @ ITER Organization
*/


#pragma once
#ifndef LOGGER_H
#define LOGGER_H

//----------------
//	START HERE
//----------------



#include <cppHeaders.h>



static std::string logFolder = "LOG_FOLDER";
static std::string logFileExtension = "_Log_File.log";
inline std::string logFileName;
static std::fstream logFileStream;




std::string GetTimeStamp();



void CreateLogFileDirectory();


void GiveLogFileName();


extern void MakeLogFile();

extern std::string WriteLogMessage(std::string s);


extern void CloseLogFile();




//----------------
//	 END HERE
//----------------

#endif // LOGGER_H
