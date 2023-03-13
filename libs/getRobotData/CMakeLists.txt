cmake_minimum_required (VERSION 3.19)
add_library(getRobotData 	src/GetRobotData.cpp
					include/GetRobotData.hpp)
message("Adding getRobotData")
target_include_directories( getRobotData PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(getRobotData robot)
#  




