cmake_minimum_required (VERSION 3.19)
add_library(rhsl_cpp 		src/rhsl.cpp
							include/rhsl.h)
message("Adding rhsl_cpp")
target_include_directories(rhsl_cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(rhsl_cpp cpp logger mymath)  




