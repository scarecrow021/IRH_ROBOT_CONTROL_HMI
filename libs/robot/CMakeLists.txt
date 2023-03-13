cmake_minimum_required (VERSION 3.19)
add_library(robot 	src/ClassDemoRobot.cpp
					src/ClassJoint.cpp
					src/ClassRobot.cpp
					src/ClassVirtualSCARA.cpp
					include/ClassDemoRobot.hpp
					include/ClassJoint.hpp
					include/ClassRobot.hpp
					include/ClassVirtualSCARA.hpp)
message("Adding robot")
target_include_directories( robot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(robot librapi cpp mymath flags trajectoryGeneration)




