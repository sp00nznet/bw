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
    # Base hierarchy (root → positioned → 3D → mobile → alive)
    core/Base.cpp
    core/GameThing.cpp
    core/GameThingWithPos.cpp
    core/Object.cpp
    core/Mobile.cpp
    core/MobileWallHug.cpp
    core/Living.cpp
    # Fixed object branch (non-moving map objects)
    core/Fixed.cpp
    core/SingleMapFixed.cpp
    core/MultiMapFixed.cpp
    core/Abode.cpp
    core/Windmill.cpp
    core/Wonder.cpp
    core/Totem.cpp
    core/Workshop.cpp
    core/StoragePit.cpp
    core/Creche.cpp
    core/Graveyard.cpp
    core/SpellDispenser.cpp
    core/TownCentre.cpp
    core/Field.cpp
    core/Feature.cpp
    core/Flowers.cpp
    core/AnimatedStatic.cpp
    core/PrayerSite.cpp
    core/WorshipSiteUpgrade.cpp
    core/MobileStatic.cpp
    core/Rock.cpp
    core/Bonfire.cpp
    core/Tree.cpp
    core/MagicTree.cpp
    core/PFootball.cpp
    core/BigForest.cpp
    # Mobile-derived entities
    core/MobileObject.cpp
    core/Pot.cpp
    core/Scaffold.cpp
    core/Arrow.cpp
    core/Poo.cpp
    core/PBall.cpp
    core/HanoiBlock.cpp
    core/Whale.cpp
    core/FieldCrop.cpp
    # Object-derived entities
    core/Furniture.cpp
    core/CitadelEntrance.cpp
    core/GWaterfall.cpp
    core/GStreetLantern.cpp
    core/ShowNeedsVisuals.cpp
    core/SpellSeed.cpp
    # GameThingWithPos-derived (non-Object)
    core/GStreetLight.cpp
    # Container branch (groups/collections)
    core/Container.cpp
    core/Citadel.cpp
    core/Flock.cpp
    core/Forest.cpp
    # Living-derived entities
    core/Villager.cpp
    core/Animal.cpp
    core/Lion.cpp
    core/Cow.cpp
    core/Dove.cpp
    core/Creature.cpp
    # Map system
    core/Map.cpp
    core/MapCoords.cpp
    # Game state
    core/Game.cpp
)

# Future subsystems (uncomment as implemented):
# add_library(bw_script STATIC script/LHVM.cpp)
# add_library(bw_terrain STATIC terrain/Landscape.cpp)
# add_library(bw_mesh STATIC mesh/L3D.cpp mesh/G3D.cpp)
