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


class Logger
{
	std::string logFolder = "LOG_FOLDER";
	std::string logFileExtension = "_Log_File.log";
	std::string logFileName;
	std::fstream logFileStream;

	// private functions
	std::string GetTimeStamp();
	void CreateLogFileDirectory();
	void GiveLogFileName();

public:
	Logger();
	~Logger();
	std::string WriteLogMessage(std::string s);

};



//----------------
//	 END HERE
//----------------

#endif // LOGGER_H
