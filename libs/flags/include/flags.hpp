/**
*	\file		flags
*	\brief		flags containing all enum flags to avoid repetition
*	\author		Soumik SARKAR @ ITER Organization
*/

#pragma once
#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <cppHeaders.hpp>



enum
{
    VIRTUAL_SIMULATOR,
    VR4ROBOTS
};

enum
{
    CONTROL_TAB,
    OPERATIONS_TAB
};
enum
{
    X_AXIS,
    Y_AXIS,
    Z_AXIS
};
enum
{
    NO_ROBOT = -2,
    VIRTUAL_SCARA,
    ROBOT_ONE,
    ROBOT_TWO,
    ROBOT_THREE,
    ROBOT_FOUR
};
enum
{
    NEGATIVE_DIRECTION = -1,
    POSITIVE_DIRECTION = 1
};
enum
{
    JOINT_1,
    JOINT_2,
    JOINT_3,
    JOINT_4,
    JOINT_5,
    JOINT_6,
    JOINT_7,
    JOINT_8,
    JOINT_9
};
enum
{
    TRANSLATION_REQUEST,
    ROTATION_REQUEST
};
enum
{
    FOUR_JOINTS = 4,
    FIVE_JOINTS,
    SIX_JOINTS,
    SEVEN_JOINTS,
    EIGHT_JOINTS,
    NINE_JOINTS
};
enum {
    JOINT_STATUS_START,
    JOINT_STATUS_SIMULATOR,
    JOINT_STATUS_READY,
    JOINT_STATUS_EMERGENCY,
    JOINT_STATUS_WARNING,
    JOINT_STATUS_HALT
};
enum
{
    TRANSLATION_AXIS,
    ROTATION_AXIS
};
enum
{
    VIRTUAL_ROBOT_OFF,
    VIRTUAL_ROBOT_ON
};
enum
{
    VIRTUAL_ROBOT_READY_OFF,
    VIRTUAL_ROBOT_READY_ON
};
enum
{
    VIRTUAL_ROBOT_STOP_OFF,
    VIRTUAL_ROBOT_STOP_ON
};
enum
{
    VR4ROBOT_OFF,
    VR4ROBOT_ON
};
enum
{
    VR4ROBOT_READY_OFF,
    VR4ROBOT_READY_ON
};
enum
{
    VR4ROBOT_WARNING_OFF,
    VR4ROBOT_WARNING_ON
};
enum
{
    VR4ROBOT_STOP_OFF,
    VR4ROBOT_STOP_ON
};





#endif // FLAGS_HPP