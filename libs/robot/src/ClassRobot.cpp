/*
//
//
#################################################################################################
#										Class Robot												#
#################################################################################################
//
//
*/



#include <ClassRobot.h>

void Robot::AddToJointVector(Joint j)
{
	joints.push_back(j);
}


void Robot::GetRobotData()
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
                auto detail = robot.second->find_value("details");
                if (detail && detail->is_list())
                {
                    int i = 0;
                    robotName = robot.second->find_value("name")->as_string();
                    joints.clear();
                    for (const auto& jointi : detail->indexed_values())
                    {
                        Joint tempJoint;
                        tempJoint.id = jointi->find_value("id")->as_string();
                        tempJoint.type = jointi->find_value("type")->as_string();
                        tempJoint.SetUnitForJoint();
                        tempJoint.min = jointi->find_value("min")->as_double();
                        tempJoint.value = jointi->find_value("current")->as_double();
                        tempJoint.max = jointi->find_value("max")->as_double();
                        AddToJointVector(tempJoint);
                        i++;
                    }
                }
            }
        }
    }
}



void Robot::MoveRobot()
{
    rapi::Client client("10.12.16.38", 50002);
    auto rapiRobot = rapi::utility::execute_function_with_first_reply(client, "vmxGetObjectHandle", rapi::String(robotName));
    if (rapiRobot && !rapiRobot->is_nil())
    {
        auto rapiJointTable = rapi::Table::create();

        for (int i = 0; i < numberOfJoints; i++)
        {
            rapiJointTable->insert(rapi::Float::create(joints.at(i).value));
        }

        auto rapiRobotKeyValuePair = std::make_pair(rapi::String::create("robot"), std::move(rapiRobot));
        auto rapiJointKeyValuePair = std::make_pair(rapi::String::create("joints"), std::move(rapiJointTable));

        auto rapiJointMessage = rapi::Table::create(rapiRobotKeyValuePair, rapiJointKeyValuePair);
        auto rapiMoveRobotVar = client.send_message("joints", "vr4robots", "SERVER", rapiJointMessage);
    }
}




/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintJointID(int _jointNum)
{
    return joints.at(_jointNum).id;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintJointType(int _jointNum)
{
    return joints.at(_jointNum).type;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintJointUnit(int _jointNum)
{
    return joints.at(_jointNum).unit;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
double Robot::GiveJointValue(int _jointNum)
{
    return joints.at(_jointNum).value;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
double Robot::GiveJointMin(int _jointNum)
{
    return joints.at(_jointNum).min;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
double Robot::GiveJointMax(int _jointNum)
{
    return joints.at(_jointNum).max;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintJointValue(int _jointNum)
{
    char t[10];
    std::sprintf(t, "%0.2f", joints.at(_jointNum).value);
    return t;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintJointMin(int _jointNum)
{
    char t[10];
    std::sprintf(t, "%0.2f", joints.at(_jointNum).min);
    return t;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintJointMax(int _jointNum)
{
    char t[10];
    std::sprintf(t, "%0.2f", joints.at(_jointNum).max);
    return t;
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
void Robot::UpdateJoint(int _jointNum, double transStep, double rotStep)
{
    if (joints.at(_jointNum).type == "translational")
    {
        if (CheckWithinLimits(_jointNum, joints.at(_jointNum).value + transStep))
        {
            joints.at(_jointNum).value = joints.at(_jointNum).value + transStep;
        }
    }
    else
    {
        if (CheckWithinLimits(_jointNum, joints.at(_jointNum).value + rotStep))
        {
            joints.at(_jointNum).value = joints.at(_jointNum).value + rotStep;
        }
    }
}

/*
void Robot::SetNewJointTarget(int _jointNum, double newJoint)
{
    if (joints.at(_jointNum).type == "translational")
    {
        if (CheckWithinLimits(_jointNum, newJoint))
        {
            joints.at(_jointNum).value = newJoint;
        }
    }
    else
    {
        if (CheckWithinLimits(_jointNum, newJoint))
        {
            joints.at(_jointNum).value = newJoint;
        }
    }
}
*/


/**
* ----------------------------------------------------------------------------------------------------------------
*/
bool Robot::CheckWithinLimits(int jointNum, double value)
{
    if (joints.at(jointNum).min <= value && value <= joints.at(jointNum).max)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/**
* ----------------------------------------------------------------------------------------------------------------
*/
void Robot::Restart()
{
    joints.clear();
}



/**
* ----------------------------------------------------------------------------------------------------------------
*/
std::string Robot::PrintRobotName()
{
    return robotName;
}




