cmake_minimum_required (VERSION 3.19)
add_library(logger 		src/logger.cpp
						include/logger.hpp)
message("Adding logger")
target_include_directories( logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(logger cpp)





