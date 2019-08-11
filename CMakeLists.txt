# Set the minimum required version 
cmake_minimum_required(VERSION 3.14)

# Project definition
project(tarnabot
        VERSION 2.0
        LANGUAGES CXX)

# Variable declaration
set(TARNABOT_BUILD_DOCS ON CACHE BOOL "")
set(TARNABOT_BUILD_APPS ON CACHE BOOL "")

#Add dependencies
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/rapidjson/CMakeLists.txt")
    message(FATAL_ERROR "rapidjson was not downloaded! GIT_SUBMODULE was turned off or    failed. Please update submodules and try again.")
endif()

#Add rapidjson
add_subdirectory(extern/rapidjson)

# Add the library
add_subdirectory(src)

# Add the examples
add_subdirectory(apps)

# Add tests
include(CTest)
