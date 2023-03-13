/**
*	\file		rhsl
*	\brief		rhsl database locations
*	\author		Soumik SARKAR @ ITER Organization
*/


#pragma once
#ifndef RHSL_HPP
#define RHSL_HPP

//----------------
//	START HERE
//----------------

#include <cppHeaders.hpp>

// folder names

static std::string databaseFolder = "DATABASES";
static std::string pointsFolder = "CARTESIAN_POINTS_DATABASE";
static std::string configurationFolder = "ROBOT_JOINTS_CONFIGURATIONS_DATABASE";
static std::string operationFolder = "ROBOT_OPERATION_SEQUENCE_DATABASE";
static std::string animationFolder = "ROBOT_ANIMATION_DATABASE";

// extensions

static std::string configurationFileXtension = ".joints";
static std::string pointFileXtension = ".point";
static std::string operationFileXtension = ".sequence";
static std::string animationFileXtension = ".anim";


//----------------
//	 END HERE
//----------------

#endif // RHSL_HPP
