project(Venus)

file(GLOB_RECURSE srcs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_library(${PROJECT_NAME} SHARED ${srcs})
add_library(avatar::shared ALIAS ${PROJECT_NAME})

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuration on macOS.")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuration on Windows.")
    add_definitions(-DVE_BUILD_DLL -DVE_PLATFORM_WINDOWS)
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/vendor/spdlog/include
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(config)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)