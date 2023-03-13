/**
*	\class      PointFile		
*	\brief		rhsl Point File parser in the database
*	\author		Soumik SARKAR @ ITER Organization
*/

#ifndef CLASS_POINT_FILE_HPP
#define CLASS_POINT_FILE_HPP

#include <rhsl.hpp>

class PointFile
{
	std::string fileName;
	std::string filePath;
	std::fstream pointFileOpen;
	bool OPEN_MODE; // True for opening in Read-Write, False for opening in Read-Only

public:
	PointFile();
	~PointFile();

	/**
	* \brief Print the path to the points database
	* \param std::string currentRobotSelected
	* \return std::string filePath
	*/

	std::string GivePointDatabasePath(std::string currentRobotSelected);
	void SetFileName(std::string openedFileName);
	void SetOpenMode(bool);
};

#endif // CLASS_POINT_FILE_HPP
