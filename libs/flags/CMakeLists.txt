cmake_minimum_required (VERSION 3.19)
add_library(flags   src/flags.cpp
                    include/flags.h)
message("Adding flags")
target_include_directories(flags PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(flags cpp)





