/**
*	\class      AnimationFile		
*	\brief		rhsl Animation File parser in the database
*	\author		Soumik SARKAR @ ITER Organization
*/

#ifndef CLASS_ANIMATION_FILE_HPP
#define CLASS_ANIMATION_FILE_HPP

#include <rhsl.hpp>

class AnimationFile
{
	std::string fileName;
	std::string filePath;
	std::fstream fileOpen;
	bool OPEN_MODE; // True for opening in Read-Write, False for opening in Read-Only

public:
	AnimationFile();
	~AnimationFile();

	/**
	* \brief Print the path to the animation database
	* \param std::string currentRobotSelected
	* \return std::string filePath
	*/

	std::string GiveAnimationDatabasePath(std::string currentRobotSelected);
	void SetFileName(std::string openedFileName);
	void SetOpenMode(bool);
};

#endif // CLASS_ANIMATION_FILE_HPP