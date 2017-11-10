# CMake minimal version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

# Project name
PROJECT(Pronostic)

# As moc files are generated in the binary dir, always look for includes there
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Run MOC when necessary
SET(CMAKE_AUTOMOC ON)

# Find QT5 Widgets module
FIND_PACKAGE(Qt5Widgets)

# Include the Qt5 Widgets files
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})

INCLUDE(${Qt5Widgets_DIR}/Qt5WidgetsConfig.cmake)

# The makefile should be verbose by default
SET(CMAKE_VERBOSE_MAKEFILE TRUE)

# Enable unit tests
ENABLE_TESTING()

# Add the definitions for the resource files
ADD_DEFINITIONS(-DROOTTODB=\"${Pronostic_SOURCE_DIR}/resource/pronostic.sqlite\")

# Add the definitions for QT5 Widgets module
ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})

# Add the compilation flags for QT5 Widgets module so the build succeed
SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Add -Wall flag at the compilation
ADD_DEFINITIONS( "-pedantic -Wno-long-long -Wall -Wextra -Wcast-align -Wcast-qual -Wformat -Wwrite-strings -Wconversion" )

# Add the subdirectories
SUBDIRS(src)