cmake_minimum_required(VERSION 3.16)
project(RaylibPracticeProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_VERSION 5.5)

# --- 1. Dependency Acquisition (Find or Fetch) ---
# Try to find raylib first
find_package(raylib ${RAYLIB_VERSION} QUIET)

if (NOT raylib_FOUND)
    message(STATUS "raylib not found locally, fetching source via FetchContent.")
    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
    endif()
endif()

# --- 2. Define Platform-Specific Linker Dependencies ---

# Initialize a variable to hold extra required libraries
set(PLATFORM_LIBS "")

# If the target system is Windows (MSVC, etc.)
if (WIN32)
    # On Windows, raylib needs explicit links to core system libraries
    list(APPEND PLATFORM_LIBS opengl32 gdi32 winmm)
    message(STATUS "Adding Windows dependencies: ${PLATFORM_LIBS}")
endif()

# --- 3. Build Executable and Link ---

add_executable(RaylibPracticeProject src/main.cpp)

# Link the core raylib library, followed by the platform-specific dependencies
target_link_libraries(RaylibPracticeProject PRIVATE
    raylib
    ${PLATFORM_LIBS}
)