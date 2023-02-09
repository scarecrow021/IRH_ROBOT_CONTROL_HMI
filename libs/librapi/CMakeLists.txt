cmake_minimum_required (VERSION 3.19)
add_library(librapi src/char.cpp 
					src/client.cpp 
					src/connection.cpp 
					src/error.cpp 
					src/list.cpp 
					src/nil.cpp 
					src/rapi_utility.cpp 
					src/stream.cpp 
					src/string.cpp 
					src/table.cpp 
					src/unique_id.cpp 
                    src/value.cpp)
message("Adding librapi")
target_include_directories( librapi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(librapi wsock32 ws2_32)





