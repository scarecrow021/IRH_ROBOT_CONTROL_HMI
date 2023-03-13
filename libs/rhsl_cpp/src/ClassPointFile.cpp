#include <ClassPointFile.hpp>

/**
* ===============================================================================================
*										Class PointFile Start
* ===============================================================================================
*/

PointFile::PointFile()
{
	// create an object of file 
}

PointFile::~PointFile()
{
	// delete this object at end of runtime..
	// not a good way to optimize memory, but let it be for now..
}

std::string PointFile::GivePointDatabasePath(std::string currentRobotSelected)
{
	filePath = databaseFolder + "/" + pointsFolder + "/" + currentRobotSelected + "/";
	return filePath;
}

void PointFile::SetOpenMode(bool mode)
{
	OPEN_MODE = mode;
}

void PointFile::SetFileName(std::string openedFileName)
{
	fileName = filePath + "/" + openedFileName;
}

/**
* ===============================================================================================
*										Class PointFile End
* ===============================================================================================
*/