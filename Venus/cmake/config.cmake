include(FetchContent)

# spdlog
FetchContent_Declare(spdlog
        GIT_TAG             v1.10.0                                             # version
        GIT_REPOSITORY      https://github.com/gabime/spdlog.git                # lib url
        SOURCE_DIR          ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog            # download path
)
FetchContent_MakeAvailable(spdlog)