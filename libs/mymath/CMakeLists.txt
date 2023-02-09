cmake_minimum_required (VERSION 3.19)
add_library(mymath 		src/mymath.cpp
						include/mymath.h)
message("Adding mymath")
target_include_directories( mymath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mymath cpp)





