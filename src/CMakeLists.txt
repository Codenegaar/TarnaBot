file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/tarnabot/*.hpp")
file(GLOB SOURCE_LIST "./*.cpp")

add_library(tarnabot ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(tarnabot PUBLIC ../include)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Headers" FILES ${HEADER_LIST})
