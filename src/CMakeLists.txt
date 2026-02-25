cmake_minimum_required(VERSION 3.20)
project(BlackAndWhite VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target: 32-bit x86 (matching original MSVC 6 binary)
if(MSVC)
    # Use __fastcall for virtual methods (matching original ABI)
    add_compile_options(/W3)
endif()

# Include paths
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Core entity hierarchy (Phase 3 - first subsystem)
add_library(bw_core STATIC
    core/Base.cpp
    core/GameThing.cpp
)

# Future subsystems (uncomment as implemented):
# add_library(bw_script STATIC script/LHVM.cpp)
# add_library(bw_terrain STATIC terrain/Landscape.cpp)
# add_library(bw_mesh STATIC mesh/L3D.cpp mesh/G3D.cpp)
