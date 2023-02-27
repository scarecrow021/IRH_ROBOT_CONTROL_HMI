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


void Robot::MoveRobot()
{
    // The syntax below is given by Tree-C, taken from one of their examples, but modified and made lean by me to work on my program efficiently.
    // 
    // Create a RAPI connection
    rapi::Client client("10.12.16.38", 50002);
    // Read Object Handle from the RAPI client (Handle = ID of the Body/Bodies Container)
    auto rapiRobot = rapi::utility::execute_function_with_first_reply(client, "vmxGetObjectHandle", rapi::String(robotName));
    if (rapiRobot && !rapiRobot->is_nil())
    {
        // Need to create a table using RAPI namespace
        auto rapiJointTable = rapi::Table::create();

        // Fill that table with joint values.
        for (int i = 0; i < numberOfJoints; i++)
        {
            // Here the 'joints' vector is our "q' vector"
            rapiJointTable->insert(rapi::Float::create(joints.at(i).value));
        }

        // RAPI need to make Key-Value pairing. It is a typical method in Computer Science. A bit slow, but it is a safe method.
        // It then makes a message with this key value pair for robots and joints, i.e., the things we are going to move.
        // 
        auto rapiRobotKeyValuePair = std::make_pair(rapi::String::create("robot"), std::move(rapiRobot));
        auto rapiJointKeyValuePair = std::make_pair(rapi::String::create("joints"), std::move(rapiJointTable));

        auto rapiJointMessage = rapi::Table::create(rapiRobotKeyValuePair, rapiJointKeyValuePair);

        // Now we use the function send_message() which is written in the RAPI Client, which sends the new joint vector to VR4ROBOTS
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




