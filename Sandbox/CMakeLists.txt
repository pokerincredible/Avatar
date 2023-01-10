project(Sandbox)

file(GLOB_RECURSE srcs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
add_executable(${PROJECT_NAME} ${srcs})

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuration on macOS.")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuration on Windows.")
    add_definitions(-DVE_PLATFORM_WINDOWS)
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        avatar::shared
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/Venus/vendor/spdlog/include
        ${CMAKE_SOURCE_DIR}/Venus/src
)