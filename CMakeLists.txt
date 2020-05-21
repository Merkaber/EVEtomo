cmake_minimum_required(VERSION 3.15)
project(EVEtomo VERSION 1.0.0 DESCRIPTION "An EVE native application which helps you with industry and market decisions")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Add path for pkg-config on windows
if(WIN32)
    set(PKG_CONFIG_EXECUTABLE "C:/msys64/mingw64/bin/pkg-config.exe")
endif(WIN32)

### Add pkg-config
find_package(PkgConfig)

### Link with gtkmm-3.0
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

### Make ryml a subproject
if(WIN32)
    add_subdirectory(../libraries/rapidyaml ryml)
endif(WIN32)

if(WIN32)
    set(SOURCE_FILES WIN32 main.cpp WindowManager.cpp WindowManager.h window/StartWindow.cpp window/StartWindow.h)
endif(WIN32)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${GTKMM_LIBRARIES} ryml)