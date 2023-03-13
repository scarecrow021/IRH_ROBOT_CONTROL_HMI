/**
*	\class      OperationFile		
*	\brief		rhsl Operation File parser in the database
*	\author		Soumik SARKAR @ ITER Organization
*/

#ifndef CLASS_OPERATION_FILE_HPP
#define CLASS_OPERATION_FILE_HPP

#include <rhsl.hpp>

class OperationFile
{
	std::string fileName;
	std::string filePath;
	std::fstream fileOpen;
	bool OPEN_MODE; // True for opening in Read-Write, False for opening in Read-Only

public:
	OperationFile();
	~OperationFile();

	/**
	* \brief Print the path to the operations database
	* \param std::string currentRobotSelected
	* \return std::string filePath
	*/

	std::string GiveOperationDatabasePath(std::string currentRobotSelected);
	void SetFileName(std::string openedFileName);
	void SetOpenMode(bool);
};

#endif // CLASS_OPERATION_FILE_HPP