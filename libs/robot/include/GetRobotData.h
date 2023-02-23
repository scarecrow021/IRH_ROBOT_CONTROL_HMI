/**
*	\file		GetRobotData
*	\brief		Robot Class for computation handling
*	\author		Soumik SARKAR @ ITER Organization
*/

#pragma once


#ifndef GET_ROBOT_DATA_H
#define GET_ROBOT_DATA_H

#include <ClassRobot.h>
#include <ClassJoint.h>


void GetRobotData(std::vector<Robot> robotContainerToBeFilled)
{
    rapi::Client client("10.12.16.38", 50002);
    rapi::Value::Ptr vr4robots = rapi::utility::get_var(client, "__vr4robots__");
    if (vr4robots && vr4robots->is_table())
    {
        auto robots = vr4robots->find_value("robots");
        if (robots->is_table())
        {
            for (const auto& robot : robots->keyed_values())
            {
                Robot tempRobot;
                auto detail = robot.second->find_value("details");
                if (detail && detail->is_list())
                {
                    int i = 0;
                    tempRobot.robotName = robot.second->find_value("name")->as_string();
                    tempRobot.joints.clear();
                    for (const auto& jointi : detail->indexed_values())
                    {
                        Joint tempJoint;
                        tempJoint.id = jointi->find_value("id")->as_string();
                        tempJoint.type = jointi->find_value("type")->as_string();
                        tempJoint.SetUnitForJoint();
                        tempJoint.min = jointi->find_value("min")->as_double();
                        tempJoint.value = jointi->find_value("current")->as_double();
                        tempJoint.max = jointi->find_value("max")->as_double();
                        tempRobot.AddToJointVector(tempJoint);
                        i++;
                    }
                }
                robotContainerToBeFilled.push_back(tempRobot);
                tempRobot.Restart();
            }
        }
    }
}


#endif // GET_ROBOT_DATA_H