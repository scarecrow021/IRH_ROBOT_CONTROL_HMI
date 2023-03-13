/**
*	\class      JointConfigFile		
*	\brief		rhsl Joint Configuration File parser in the database
*	\author		Soumik SARKAR @ ITER Organization
*/

#ifndef CLASS_JOINT_CONFIG_FILE_HPP
#define CLASS_JOINT_CONFIG_FILE_HPP

#include <rhsl.hpp>

class JointConfigFile
{
	std::string fileName;
	std::string filePath;
	std::fstream fileOpen;
	bool OPEN_MODE; // True for opening in Read-Write, False for opening in Read-Only

public:
	JointConfigFile();
	~JointConfigFile();

	/**
	* \brief Print the path to the joint configuration database
	* \param std::string currentRobotSelected
	* \return std::string filePath
	*/

	std::string GiveJointConfigDatabasePath(std::string currentRobotSelected);
	void SetFileName(std::string openedFileName);
	void SetOpenMode(bool);
};

#endif // CLASS_JOINT_CONFIG_FILE_HPP