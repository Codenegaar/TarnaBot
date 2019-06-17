cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME "tarnabot")
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PACKAGE_VERSION 1.0.0)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/ TARNABOT_SOURCES)
file(GLOB TARNABOT_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_library(${PROJECT_NAME} SHARED ${TARNABOT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) #had to do this because all includes starts with "include/"

find_package(Threads REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
qt5_use_modules(${PROJECT_NAME} Core Network)

set_target_properties(${PROJECT_NAME}
                        PROPERTIES 
                              FRAMEWORK ON
                              SOVERSION 0
                              VERSION "${PACKAGE_VERSION}"
                              PUBLIC_HEADER "${TARNABOT_INCLUDES}"
                              OUTPUT_NAME ${PROJECT_NAME}
                     )

install(TARGETS ${PROJECT_NAME}
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
        LIBRARY DESTINATION lib)

