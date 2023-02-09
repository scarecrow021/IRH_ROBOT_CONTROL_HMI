cmake_minimum_required (VERSION 3.19)
add_library(trajectoryGeneration 	src/ClassPoint.cpp
									include/ClassPoint.h)
message("Adding trajectoryGeneration")
target_include_directories( trajectoryGeneration PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(cpp logger mymath)
target_link_libraries(trajectoryGeneration cpp logger mymath)
#   




