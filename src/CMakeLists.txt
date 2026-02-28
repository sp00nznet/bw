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
    core/WorshipSite.cpp
    core/WorshipSpellIcon.cpp
    core/WorshipTotem.cpp
    core/MobileStatic.cpp
    core/Rock.cpp
    core/Bonfire.cpp
    core/Fragment.cpp
    core/DeadTree.cpp
    core/Tree.cpp
    core/MagicTree.cpp
    core/MagicTeleport.cpp
    core/PFootball.cpp
    core/BigForest.cpp
    core/CitadelPart.cpp
    core/CitadelHeart.cpp
    core/TotemStatue.cpp
    core/LandscapeVortex.cpp
    # Mobile-derived entities
    core/MobileObject.cpp
    core/Pot.cpp
    core/PotStructure.cpp
    core/PileResource.cpp
    core/PileFood.cpp
    core/PileWood.cpp
    core/MagicFood.cpp
    core/MagicWood.cpp
    core/Scaffold.cpp
    core/Arrow.cpp
    core/Poo.cpp
    core/PBall.cpp
    core/HanoiBlock.cpp
    core/Ball.cpp
    core/OneOffSpellSeed.cpp
    core/Whale.cpp
    core/FieldCrop.cpp
    # Object-derived entities
    core/Furniture.cpp
    core/CitadelEntrance.cpp
    core/GWaterfall.cpp
    core/GStreetLantern.cpp
    core/ShowNeedsVisuals.cpp
    core/HelpSpirit.cpp
    core/MagicFireBall.cpp
    core/SpellSeed.cpp
    core/FireFly.cpp
    core/Reward.cpp
    core/TownDesireFlags.cpp
    core/SpellIcon.cpp
    core/FishFarm.cpp
    core/Football.cpp
    core/MapShield.cpp
    core/MagicShield.cpp
    core/PhysicalShield.cpp
    # Object-derived entities (additional)
    core/ScriptHighlight.cpp
    core/FelledTree.cpp
    # Camera system
    core/CameraMode.cpp
    core/GCamera.cpp
    # GameThingWithPos-derived (non-Object)
    core/GStreetLight.cpp
    core/Arena.cpp
    core/Meeting.cpp
    core/WayPoint.cpp
    core/ScriptTimer.cpp
    core/ScriptMarker.cpp
    core/WeatherThing.cpp
    core/Mist.cpp
    core/InfluenceRing.cpp
    core/GParticleContainer.cpp
    core/SpellSeedGraphic.cpp
    core/Spell.cpp
    core/SpellWithObjects.cpp
    core/SpellHeal.cpp
    core/SpellForest.cpp
    core/SpellResource.cpp
    core/SpellCreature.cpp
    core/SpellWater.cpp
    core/SpellStormAndTornado.cpp
    core/SpellShield.cpp
    core/SpellTeleport.cpp
    core/SpellFlock.cpp
    core/SpellFlockFlying.cpp
    core/SpellFlockGround.cpp
    core/PlannedMultiMapFixed.cpp
    core/PlannedAbode.cpp
    core/PlannedFeature.cpp
    core/PlannedCitadelPart.cpp
    core/PlannedCitadelHeart.cpp
    core/PlannedCreaturePen.cpp
    core/PlannedWorshipSite.cpp
    core/PlannedWorshipSiteUpgrade.cpp
    core/PlannedTownCitadelHeart.cpp
    core/PlannedTownCentre.cpp
    # BuildingSite branch (GameThing-derived construction management)
    core/BuildingSite.cpp
    core/StandardBuildingSite.cpp
    core/CitadelBuildingSite.cpp
    core/WorkshopBuildingSite.cpp
    # GameThing-derived (non-positional)
    core/TownArtifact.cpp
    core/Playtime.cpp
    core/DancePathInfo.cpp
    core/GMagicHand.cpp
    core/GClimate.cpp
    core/Reaction.cpp
    core/GLeashStatus.cpp
    core/DanceGroup.cpp
    core/DanceKeyFrame.cpp
    core/GStream.cpp
    core/GInterfaceMessageBuffer.cpp
    core/VortexSave.cpp
    core/DataPath.cpp
    core/GameStats.cpp
    core/FireEffect.cpp
    core/ShowNeeds.cpp
    core/GFootpath.cpp
    core/GFootpathLink.cpp
    core/GFootpathNode.cpp
    core/GFootpathLinkSave.cpp
    # Computer player / AI system
    core/PlayerComputer.cpp
    core/GAudio.cpp
    core/PlaytimeElement.cpp
    # Sound system
    core/SoundTag.cpp
    # Container branch (groups/collections)
    core/Container.cpp
    core/Town.cpp
    core/Citadel.cpp
    core/Flock.cpp
    core/Forest.cpp
    # Living-derived entities
    core/Villager.cpp
    core/Animal.cpp
    core/Lion.cpp
    core/Leopard.cpp
    core/Tiger.cpp
    core/Wolf.cpp
    core/Cow.cpp
    core/Horse.cpp
    core/Sheep.cpp
    core/Pig.cpp
    core/Goat.cpp
    core/Tortoise.cpp
    core/Zebra.cpp
    core/Dove.cpp
    core/Crow.cpp
    core/Pigeon.cpp
    core/Seagull.cpp
    core/Swallow.cpp
    core/Vulture.cpp
    core/Bat.cpp
    core/SpecialVillager.cpp
    core/Creature.cpp
    # Creature AI subsystem (belief/mental model)
    core/CreatureBeliefList.cpp
    core/CreatureBeliefs.cpp
    core/CreatureGlobalExplorationMap.cpp
    core/CreatureMental.cpp
    core/Prss.cpp
    core/CreatureSelect.cpp
    core/MultiplayerDatabase.cpp
    core/CreatureDatabase.cpp
    core/CreaturePen.cpp
    core/SubArgument.cpp
    # Hand state system
    core/HandState.cpp
    # Dance/GroupBehaviour subsystem
    core/PlayerMessage.cpp
    core/GroupBehaviour.cpp
    core/Dance.cpp
    # Base-derived (utility/data)
    core/GAlignment.cpp
    core/GBelief.cpp
    core/TownStats.cpp
    core/TownDesire.cpp
    # Town spell icons
    core/TownSpellIcon.cpp
    core/TownCentreSpellIcon.cpp
    # Player system
    core/Player.cpp
    # Map system
    core/Map.cpp
    core/MapCoords.cpp
    # Game state
    core/Game.cpp
    # UI option entry hierarchy
    core/SubOptionEntry.cpp
    core/FuncT.cpp
)

# Future subsystems (uncomment as implemented):
# add_library(bw_script STATIC script/LHVM.cpp)
# add_library(bw_terrain STATIC terrain/Landscape.cpp)
# add_library(bw_mesh STATIC mesh/L3D.cpp mesh/G3D.cpp)
