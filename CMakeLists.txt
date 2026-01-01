# Minimal CMake project for CLion indexing only
cmake_minimum_required(VERSION 3.25.1)
project(ps3dev-hello-world C CXX)

# -----------------------------
# IDE include directories only
# -----------------------------
if (DEFINED ENV{PS3DEV})
    include_directories(
            # PPU includes
            $ENV{PS3DEV}/ppu/include
            $ENV{PS3DEV}/ppu/include/sys
            $ENV{PS3DEV}/ppu/include/io
            # SPU includes
            #$ENV{PS3DEV}/ppu/include
    )
endif ()

# -----------------------------
# Add source files for IDE indexing
# -----------------------------
file(GLOB_RECURSE PROJECT_SOURCES
        "${CMAKE_SOURCE_DIR}/source/*.c"
        "${CMAKE_SOURCE_DIR}/source/*.cpp"
)

# -----------------------------
# Dummy target for CLion indexing
# -----------------------------
# This target will not be used for building.
add_executable(dummy_target ${PROJECT_SOURCES})

# -----------------------------
# Do not override Makefile build
# -----------------------------
set_target_properties(dummy_target PROPERTIES
        EXCLUDE_FROM_ALL TRUE   # ensures 'make' does not build this target
)
