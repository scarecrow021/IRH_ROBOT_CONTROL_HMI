cmake_minimum_required (VERSION 3.19)
add_library(cpp     src/cppHeaders.cpp
                    include/cppHeaders.hpp)
message("Adding cpp")
target_include_directories( cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)






