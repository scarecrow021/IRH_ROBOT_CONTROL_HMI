cmake_minimum_required(VERSION 3.5)

project(qt_irh_rchmi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_subdirectory(libs)


set(PROJECT_SOURCES
        MainHMI/src/main.cpp
        MainHMI/src/connectionsHMI.cpp
        MainHMI/src/connectionsJointWidget.cpp
        MainHMI/src/debug.cpp
        MainHMI/src/hmiDemoRobot.cpp
        MainHMI/src/hmiJointWidgets.cpp
        MainHMI/src/hmiLED.cpp
        MainHMI/src/hmiVirtualJoystick.cpp
        MainHMI/src/ITER_Logo_NoonYellow.png
        MainHMI/src/jointcontrolbox.cpp
        MainHMI/src/jointcontrolbox.ui
        MainHMI/src/mainhmi.cpp
        MainHMI/src/mainhmi.ui
        MainHMI/src/startupUIFunctions.cpp
        MainHMI/include/jointcontrolbox.h
        MainHMI/include/mainhmi.h
        MainHMI/include/qtHeaders.h
        MainHMI/include/resource.h
)

include_directories("MainHMI/include")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt_irh_rchmi
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET qt_irh_rchmi APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qt_irh_rchmi SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qt_irh_rchmi
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(qt_irh_rchmi PRIVATE Qt${QT_VERSION_MAJOR}::Widgets cpp robot logger mymath rhsl_cpp)

set_target_properties(qt_irh_rchmi PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS qt_irh_rchmi
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qt_irh_rchmi)
endif()
