#pragma once
// PSysProperties — particle system modifier data types
// All extend BaseAtomModifierData or BaseCollectionModifierData at size 0x14
// Struct layouts from bw1-decomp (71 types)

#include "PSysModifiers.h"

#include <stdint.h>

// === Atom modifier data types (extend BaseAtomModifierData, 0x14 bytes each) ===

struct AR_FadeOutOnceConditionTrue__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(AR_FadeOutOnceConditionTrue__AtomData) == 0x14, "AR_FadeOutOnceConditionTrue__AtomData size mismatch");

struct AddSoundToAtom__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(AddSoundToAtom__AtomData) == 0x14, "AddSoundToAtom__AtomData size mismatch");

struct AddSubCollectionsToAtom__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(AddSubCollectionsToAtom__AtomData) == 0x14, "AddSubCollectionsToAtom__AtomData size mismatch");

struct AttatchFireBallToAtom__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(AttatchFireBallToAtom__AtomData) == 0x14, "AttatchFireBallToAtom__AtomData size mismatch");

struct CheckShieldDeflections__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(CheckShieldDeflections__AtomData) == 0x14, "CheckShieldDeflections__AtomData size mismatch");

struct CreateNewBaseAtom__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(CreateNewBaseAtom__AtomData) == 0x14, "CreateNewBaseAtom__AtomData size mismatch");

struct ER_GlintsOnTarget__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(ER_GlintsOnTarget__AtomData) == 0x14, "ER_GlintsOnTarget__AtomData size mismatch");

struct ER_GlintsOnTarget__ParentAtomData : public BaseAtomModifierData {};
static_assert(sizeof(ER_GlintsOnTarget__ParentAtomData) == 0x14, "ER_GlintsOnTarget__ParentAtomData size mismatch");

struct ER_MultiPickup__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(ER_MultiPickup__AtomData) == 0x14, "ER_MultiPickup__AtomData size mismatch");

struct RemoveRuleAfterConditionTrue__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(RemoveRuleAfterConditionTrue__AtomData) == 0x14, "RemoveRuleAfterConditionTrue__AtomData size mismatch");

struct RemoveSoundFromAtom__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(RemoveSoundFromAtom__AtomData) == 0x14, "RemoveSoundFromAtom__AtomData size mismatch");

struct UR_Articulate__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_Articulate__AtomData) == 0x14, "UR_Articulate__AtomData size mismatch");

struct UR_BankedTurning__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_BankedTurning__AtomData) == 0x14, "UR_BankedTurning__AtomData size mismatch");

struct UR_BeliefSprite__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_BeliefSprite__AtomData) == 0x14, "UR_BeliefSprite__AtomData size mismatch");

struct UR_CloudGather__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_CloudGather__AtomData) == 0x14, "UR_CloudGather__AtomData size mismatch");

struct UR_CreatureSpellGeneric__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_CreatureSpellGeneric__AtomData) == 0x14, "UR_CreatureSpellGeneric__AtomData size mismatch");

struct UR_Explosion__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_Explosion__AtomData) == 0x14, "UR_Explosion__AtomData size mismatch");

struct UR_FollowTargets__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_FollowTargets__AtomData) == 0x14, "UR_FollowTargets__AtomData size mismatch");

struct UR_ForestPath__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_ForestPath__AtomData) == 0x14, "UR_ForestPath__AtomData size mismatch");

struct UR_HealSpellChakra__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_HealSpellChakra__AtomData) == 0x14, "UR_HealSpellChakra__AtomData size mismatch");

struct UR_InitialSpin__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_InitialSpin__AtomData) == 0x14, "UR_InitialSpin__AtomData size mismatch");

struct UR_LightSheetOnObject__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_LightSheetOnObject__AtomData) == 0x14, "UR_LightSheetOnObject__AtomData size mismatch");

struct UR_LightningStrike__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_LightningStrike__AtomData) == 0x14, "UR_LightningStrike__AtomData size mismatch");

struct UR_ManaPathNew__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_ManaPathNew__AtomData) == 0x14, "UR_ManaPathNew__AtomData size mismatch");

struct UR_ObjectArcer__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_ObjectArcer__AtomData) == 0x14, "UR_ObjectArcer__AtomData size mismatch");

struct UR_OrientSpriteWithRandomAngle__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_OrientSpriteWithRandomAngle__AtomData) == 0x14, "UR_OrientSpriteWithRandomAngle__AtomData size mismatch");

struct UR_OrientSpriteWithVelocity__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_OrientSpriteWithVelocity__AtomData) == 0x14, "UR_OrientSpriteWithVelocity__AtomData size mismatch");

struct UR_OrientWithVelocity__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_OrientWithVelocity__AtomData) == 0x14, "UR_OrientWithVelocity__AtomData size mismatch");

struct UR_SideSpin__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_SideSpin__AtomData) == 0x14, "UR_SideSpin__AtomData size mismatch");

struct UR_SimpleBeam__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_SimpleBeam__AtomData) == 0x14, "UR_SimpleBeam__AtomData size mismatch");

struct UR_SphereSurfaceTracer__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_SphereSurfaceTracer__AtomData) == 0x14, "UR_SphereSurfaceTracer__AtomData size mismatch");

struct UR_StormCast__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_StormCast__AtomData) == 0x14, "UR_StormCast__AtomData size mismatch");

struct UR_TownCentreBelief__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_TownCentreBelief__AtomData) == 0x14, "UR_TownCentreBelief__AtomData size mismatch");

struct UR_VapourEndEffect__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_VapourEndEffect__AtomData) == 0x14, "UR_VapourEndEffect__AtomData size mismatch");

struct UR_VolFXOnObject__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_VolFXOnObject__AtomData) == 0x14, "UR_VolFXOnObject__AtomData size mismatch");

struct UR_VortexAttract__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_VortexAttract__AtomData) == 0x14, "UR_VortexAttract__AtomData size mismatch");

struct UpdateRuleGravityWithFloor__AtomDataRipple : public BaseAtomModifierData {};
static_assert(sizeof(UpdateRuleGravityWithFloor__AtomDataRipple) == 0x14, "UpdateRuleGravityWithFloor__AtomDataRipple size mismatch");

struct UpdateRuleShieldSpark__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UpdateRuleShieldSpark__AtomData) == 0x14, "UpdateRuleShieldSpark__AtomData size mismatch");

struct ZR_ChainGesture__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(ZR_ChainGesture__AtomData) == 0x14, "ZR_ChainGesture__AtomData size mismatch");

// === Collection modifier data types (extend BaseCollectionModifierData, 0x14 bytes each) ===

struct ER_BurstFromParentAtom__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(ER_BurstFromParentAtom__CollectionData) == 0x14, "ER_BurstFromParentAtom__CollectionData size mismatch");

struct ER_EmitFromParentAtom__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(ER_EmitFromParentAtom__CollectionData) == 0x14, "ER_EmitFromParentAtom__CollectionData size mismatch");

struct ER_MultiPickup__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(ER_MultiPickup__CollectionData) == 0x14, "ER_MultiPickup__CollectionData size mismatch");

struct EmitterRule__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(EmitterRule__CollectionData) == 0x14, "EmitterRule__CollectionData size mismatch");

struct EmitterRuleLightningSprite__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(EmitterRuleLightningSprite__CollectionData) == 0x14, "EmitterRuleLightningSprite__CollectionData size mismatch");

struct LightningForkFlicker__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(LightningForkFlicker__CollectionData) == 0x14, "LightningForkFlicker__CollectionData size mismatch");

struct UR_AddDefensiveSphere__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_AddDefensiveSphere__CollectionData) == 0x14, "UR_AddDefensiveSphere__CollectionData size mismatch");

struct UR_Articulate__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Articulate__CollectionData) == 0x14, "UR_Articulate__CollectionData size mismatch");

struct UR_AtomsAtEPTarget__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_AtomsAtEPTarget__CollectionData) == 0x14, "UR_AtomsAtEPTarget__CollectionData size mismatch");

struct UR_CloudGather__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CloudGather__CollectionData) == 0x14, "UR_CloudGather__CollectionData size mismatch");

struct UR_CloudMoverNew__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CloudMoverNew__CollectionData) == 0x14, "UR_CloudMoverNew__CollectionData size mismatch");

struct UR_CreatureSpell__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CreatureSpell__CollectionData) == 0x14, "UR_CreatureSpell__CollectionData size mismatch");

struct UR_CreatureSpellCompassion__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CreatureSpellCompassion__CollectionData) == 0x14, "UR_CreatureSpellCompassion__CollectionData size mismatch");

struct UR_CreatureSpellFreeze__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CreatureSpellFreeze__CollectionData) == 0x14, "UR_CreatureSpellFreeze__CollectionData size mismatch");

struct UR_CreatureSpellGeneric__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CreatureSpellGeneric__CollectionData) == 0x14, "UR_CreatureSpellGeneric__CollectionData size mismatch");

struct UR_CreatureSpellItch__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_CreatureSpellItch__CollectionData) == 0x14, "UR_CreatureSpellItch__CollectionData size mismatch");

struct UR_Explosion__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Explosion__CollectionData) == 0x14, "UR_Explosion__CollectionData size mismatch");

struct UR_Flocking__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Flocking__CollectionData) == 0x14, "UR_Flocking__CollectionData size mismatch");

struct UR_FollowTargets__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_FollowTargets__CollectionData) == 0x14, "UR_FollowTargets__CollectionData size mismatch");

struct UR_HandSprinkle__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_HandSprinkle__CollectionData) == 0x14, "UR_HandSprinkle__CollectionData size mismatch");

struct UR_LightSheetOnObject__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_LightSheetOnObject__CollectionData) == 0x14, "UR_LightSheetOnObject__CollectionData size mismatch");

struct UR_Lightning_CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Lightning_CollectionData) == 0x14, "UR_Lightning_CollectionData size mismatch");

struct UR_PlasmaInf : public BaseCollectionModifierData {};
static_assert(sizeof(UR_PlasmaInf) == 0x14, "UR_PlasmaInf size mismatch");

struct UR_RingSpin__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_RingSpin__CollectionData) == 0x14, "UR_RingSpin__CollectionData size mismatch");

struct UR_Rope__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Rope__CollectionData) == 0x14, "UR_Rope__CollectionData size mismatch");

struct UR_SimpleBeam__SubCollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_SimpleBeam__SubCollectionData) == 0x14, "UR_SimpleBeam__SubCollectionData size mismatch");

struct UR_StormCast__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_StormCast__CollectionData) == 0x14, "UR_StormCast__CollectionData size mismatch");

struct UR_TownCentreBelief__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_TownCentreBelief__CollectionData) == 0x14, "UR_TownCentreBelief__CollectionData size mismatch");

struct UR_Trail__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Trail__CollectionData) == 0x14, "UR_Trail__CollectionData size mismatch");

struct UR_WillowWisp__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_WillowWisp__CollectionData) == 0x14, "UR_WillowWisp__CollectionData size mismatch");

struct ZR_ChainGesture__ParentCollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(ZR_ChainGesture__ParentCollectionData) == 0x14, "ZR_ChainGesture__ParentCollectionData size mismatch");

struct ZR_SurfRevol__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(ZR_SurfRevol__CollectionData) == 0x14, "ZR_SurfRevol__CollectionData size mismatch");

// === Additional PSys modifier data from PSysTornado.h and PSysAtomCore.h ===

struct UR_Tornado__CollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Tornado__CollectionData) == 0x14, "UR_Tornado__CollectionData size mismatch");

struct UR_Tornado__DebrisCollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Tornado__DebrisCollectionData) == 0x14, "UR_Tornado__DebrisCollectionData size mismatch");

struct UR_Tornado__FlyingAtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_Tornado__FlyingAtomData) == 0x14, "UR_Tornado__FlyingAtomData size mismatch");

struct UR_Tornado__FlyingCollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Tornado__FlyingCollectionData) == 0x14, "UR_Tornado__FlyingCollectionData size mismatch");

struct UR_GesturingRecognised__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_GesturingRecognised__AtomData) == 0x14, "UR_GesturingRecognised__AtomData size mismatch");

struct UR_Plasma__AtomData : public BaseAtomModifierData {};
static_assert(sizeof(UR_Plasma__AtomData) == 0x14, "UR_Plasma__AtomData size mismatch");

struct UR_Plasma__SubCollectionData : public BaseCollectionModifierData {};
static_assert(sizeof(UR_Plasma__SubCollectionData) == 0x14, "UR_Plasma__SubCollectionData size mismatch");

