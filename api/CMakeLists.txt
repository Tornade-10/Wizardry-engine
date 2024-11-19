file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(api ${SRC_FILES} ${HEADER_FILES})
target_include_directories(api PUBLIC include/)

# GTest and SDL2 packages
find_package(GTest CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(Imgui CONFIG REQUIRED)

if(ENABLE_PROFILING)
    target_link_libraries(api PRIVATE Tracy::TracyClient)
    target_compile_definitions(api PUBLIC TRACY_ENABLE=1)
endif(ENABLE_PROFILING)

# Link main with core, api, and SDL2 libraries
target_link_libraries(api PRIVATE core SDL2::SDL2 SDL2::SDL2main imgui::imgui)

target_link_libraries(api PRIVATE)