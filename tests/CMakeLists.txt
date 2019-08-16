set(SOURCE_LIST
    usertest.cpp)
find_package(Catch2 REQUIRED)

add_executable(tarnabot-test ${SOURCE_LIST})

target_link_libraries(tarnabot-test PRIVATE tarnabot)
target_link_libraries(tarnabot-test PRIVATE Catch2::Catch2)
target_link_libraries(tarnabot-test PRIVATE jsoncpp)

include(CTest)
include(Catch)
catch_discover_tests(tarnabot-test)
