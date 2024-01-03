# January 2nd, 2024
# 5:10pm - 7:03pm
# 7:14pm - 8:48pm

cmake_minimum_required(VERSION 3.5)

project(EmployeeRecruitment VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        professionaldegreecombo.h
        professionaldegreecombo.cpp
        experiencecombo.h
        experiencecombo.cpp
        integercombo.h
        integercombo.cpp
        jobcombo.h
        jobcombo.cpp
        skillchecklist.h
        skillchecklist.cpp
        operationmanagerskilllist.h
        operationmanagerskilllist.cpp
        maintenancebossskilllist.h
        maintenancebossskilllist.cpp
        securitybossskilllist.h
        securitybossskilllist.cpp
        electricaltechnicianskilllist.h
        electricaltechnicianskilllist.cpp
        operatorskilllist.h
        operatorskilllist.cpp
        databasemanager.h
        databasemanager.cpp
        employee.h
        employee.cpp
        employeetabledialog.h
        employeetabledialog.cpp
        employeetabledialog.ui
        enums.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(EmployeeRecruitment
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET EmployeeRecruitment APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(EmployeeRecruitment SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(EmployeeRecruitment
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(EmployeeRecruitment PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(EmployeeRecruitment PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_include_directories(EmployeeRecruitment PRIVATE .)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.EmployeeRecruitment)
endif()
set_target_properties(EmployeeRecruitment PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS EmployeeRecruitment
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(EmployeeRecruitment)
endif()
