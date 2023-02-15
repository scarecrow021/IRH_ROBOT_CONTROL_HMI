/*
//
//
#################################################################################################
#										Logger Functions										#
#################################################################################################
//
//
*/

#include <logger.h>

std::string Logger::GetTimeStamp()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int y = 1900 + ltm->tm_year;
	int m = 1 + ltm->tm_mon;
	int d = ltm->tm_mday;
	int h = ltm->tm_hour;
	int mm = ltm->tm_min;
	int s = ltm->tm_sec;
	std::string timeStamp;
	timeStamp = "<" + std::to_string(y) + "-" + std::to_string(m) + "-" + std::to_string(d) + "||";
	timeStamp = timeStamp + std::to_string(h) + ":" + std::to_string(mm) + ":" + std::to_string(s) + ">";
	return timeStamp;
}

void Logger::CreateLogFileDirectory()
{
	if (!std::filesystem::is_directory(logFolder))
	{
		std::filesystem::create_directory(logFolder);
	}
}

void Logger::GiveLogFileName()
{
	std::string logTimeStamp = GetTimeStamp();
	logTimeStamp.erase(remove_if(logTimeStamp.begin(), logTimeStamp.end(), ::isspace), logTimeStamp.end());
	replace(logTimeStamp.begin(), logTimeStamp.end(), '<', '[');
	replace(logTimeStamp.begin(), logTimeStamp.end(), '>', ']');
	replace(logTimeStamp.begin(), logTimeStamp.end(), ':', '_');
	replace(logTimeStamp.begin(), logTimeStamp.end(), '|', '_');
	logFileName = logFolder + "/" + logTimeStamp + logFileExtension;
}

std::string Logger::WriteLogMessage(std::string s)
{
	std::string logMessage = GetTimeStamp() + " " + s;
	logFileStream << logMessage << std::endl;
	return logMessage;
}



Logger::Logger()
{
	CreateLogFileDirectory();
	GiveLogFileName();
	logFileStream.open(logFileName, std::fstream::in | std::fstream::out | std::fstream::app);
	WriteLogMessage("Log File Initiated");
}


Logger::~Logger()
{
	WriteLogMessage("Application Exit: Log File Closed");
	logFileStream.close();
}