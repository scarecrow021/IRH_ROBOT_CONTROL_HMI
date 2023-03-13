cmake_minimum_required (VERSION 3.19)
add_library(rhsl_cpp 		src/rhsl.cpp
							src/ClassAnimationFile.cpp
							src/ClassJointConfigFile.cpp
							src/ClassOperationFile.cpp
							src/ClassPointFile.cpp
							include/rhsl.hpp
							include/ClassAnimationFile.hpp
							include/ClassJointConfigFile.hpp
							include/ClassOperationFile.hpp
							include/ClassPointFile.hpp)
message("Adding rhsl_cpp")
target_include_directories(rhsl_cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(rhsl_cpp cpp logger mymath)  




