cmake_minimum_required (VERSION 3.19)
project (VR4_GUI_V2)# Enter your Project Name
# Set Project Version Number, however if you do not have an idea keep as it is.
# This helps in creating version control for a project which has a repository tool like Git 
set (VR4_GUI_V2_VERSION_MAJOR 1)
set (VR4_GUI_V2_VERSION_MINOR 0)

# Keep this as it is.
if (MSVC_VERSION GREATER_EQUAL "1900")
    set (CMAKE_CXX_STANDARD 17)
else()
	set (CMAKE_CXX_STANDARD 14)
endif()
# Keep this as it is.
# Add cmake resources to generate run config
include(CreateLaunchers.cmake)
# DEPENDENCIES DIR
set(DEPENDENCIES_DIR "C:/") # Let this be the folder where you have installed Qt.
#  Qt
set(QT_DIR "${DEPENDENCIES_DIR}/Qt/6.4.0/msvc2019_64/" CACHE PATH "Qt dir")
# Find the msvc compiler and set the path here. Or else leave this as it is and we will correct it with CMake GUI


#Use solution folders. Leave this as it is..!
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Don't care about this.. This macro finds all the relevant files you would need to compile your project!
MACRO(SUBDIRLIST result curdir i)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist_${i} "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      set(dir ${curdir}/${child})
      message(${dir})
      SUBDIRLIST(dirlist ${dir} i++)
      LIST(APPEND dirlist ${dir})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})

ENDMACRO()


# add specific flag for debug :
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_DEBUG_POSTFIX d)
# These two set functions are specific for cmake, so leave them as it is..

# This is important!
# If you want Cmake to recognize any subproject folder and it's cmakelist.txt, 
# you need to use the function add_subdirectory()....
# for example, we shall use RAPI library, so we do the following:
# add_subdirectory(librapi)
# message("Adding LibRAPI").... The message function is optional!!!
# Add sub-directories

# Add sub-directories

add_subdirectory(libs)
message("Successfully added libs")

add_subdirectory(MainHMI)
message("Adding MainHMI ...")


