cmake_minimum_required(VERSION 3.16)

project(LocalSend VERSION 0.1 LANGUAGES CXX)

#=========================== INCLUSION OF Qt ============================#

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

#=========================== INCLUSION OF Project Files ============================#

set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)


#=========================== SETUP EXECTUABLE ============================#


#Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

#Add the executable
add_executable(LocalSend WIN32 ${SOURCES})


#Add the target includes for the project
target_include_directories(LocalSend PRIVATE ${FORMS_DIR})
target_include_directories(LocalSend PRIVATE ${INCLUDE_DIR})
target_include_directories(LocalSend PRIVATE ${SOURCE_DIR})





#=========================== LINKING LIBRARIES ==========================#
target_link_libraries(LocalSend PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#include(GNUInstallDirs)
#install(TARGETS LocalSend
#    BUNDLE DESTINATION .
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(LocalSend)
#endif()