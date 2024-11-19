cmake_minimum_required(VERSION 3.18)

project(Wizardry-engine)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# GTest and SDL2 packages
find_package(GTest CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(Imgui CONFIG REQUIRED)

# Optionally enable profiling
option(ENABLE_PROFILING "Enable Tracy Profiling" OFF)

if(ENABLE_PROFILING)
    find_package(Tracy CONFIG REQUIRED)
endif()

# Add core and API subdirectories
add_subdirectory(core/)
add_subdirectory(api/)

# Add main executable
add_executable(main main.cc)

# Link main with core, api, and SDL2 libraries
target_link_libraries(main PRIVATE core api SDL2::SDL2 SDL2::SDL2main GTest::gtest GTest::gtest_main imgui::imgui)

# Copy resources
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
