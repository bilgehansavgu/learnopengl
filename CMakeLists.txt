cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/dependencies/include
    ${CMAKE_SOURCE_DIR}/include
)

# Add library directories
link_directories(
    ${CMAKE_SOURCE_DIR}/dependencies/library
)

# Recursively collect all source files in the core/ directory
file(GLOB_RECURSE CORE_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

# Add the main executable
add_executable(LearnOpenGL
    ${CORE_SOURCES}
)

# Platform-specific settings
if(APPLE)
    # macOS-specific libraries and frameworks
    find_library(OPENGL_LIBRARY OpenGL REQUIRED)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation REQUIRED)

    target_link_libraries(LearnOpenGL
        ${OPENGL_LIBRARY}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY}
        ${COREFOUNDATION_LIBRARY}
        ${CMAKE_SOURCE_DIR}/dependencies/library/libglfw.3.dylib
    )
    
elseif(WIN32 AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64-bit Windows-specific libraries
    target_link_libraries(LearnOpenGL
        ${CMAKE_SOURCE_DIR}/dependencies/library/glfw3.lib
        opengl32
    )
endif()

# Set common compiler flags
target_compile_options(LearnOpenGL PRIVATE
    -fcolor-diagnostics
    -Wall
    -fansi-escape-codes
    -g
    -Wno-deprecated
)

# ==================================================
# Uncomment this section if you want to build each example as a separate executable.
# ==================================================

# # Collect source files for each example
# file(GLOB HELLO_WINDOW_SOURCES ${CMAKE_SOURCE_DIR}/src/1-HelloWindow/*.cpp)
# file(GLOB HELLO_TRIANGLE_SOURCES ${CMAKE_SOURCE_DIR}/src/2-HelloTriangle/*.cpp)
# file(GLOB SHADERS_SOURCES ${CMAKE_SOURCE_DIR}/src/3-Shaders/*.cpp)
# file(GLOB INTERACTIVE_CG_SOURCES ${CMAKE_SOURCE_DIR}/src/InteractiveCG/*.cpp)

# # Add executables for each example
# add_executable(HelloWindow ${HELLO_WINDOW_SOURCES})
# add_executable(HelloTriangle ${HELLO_TRIANGLE_SOURCES})
# add_executable(Shaders ${SHADERS_SOURCES})
# add_executable(InteractiveCG ${INTERACTIVE_CG_SOURCES})

# # Link the main LearnOpenGL executable to each example
# target_link_libraries(HelloWindow LearnOpenGL)
# target_link_libraries(HelloTriangle LearnOpenGL)
# target_link_libraries(Shaders LearnOpenGL)
# target_link_libraries(InteractiveCG LearnOpenGL)

# ==================================================