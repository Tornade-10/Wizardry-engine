file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(core ${SRC_FILES} ${HEADER_FILES})
target_include_directories(core PUBLIC include/)

if(ENABLE_PROFILING)
    target_link_libraries(core PRIVATE Tracy::TracyClient)
endif(ENABLE_PROFILING)

file(GLOB_RECURSE TEST_FILES test/*.cc)
add_executable(core_test ${TEST_FILES})

target_link_libraries(core_test PRIVATE core GTest::gtest GTest::gtest_main)

add_test(Core core_test)