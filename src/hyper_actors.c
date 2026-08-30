#include "modding.h"
#include "functions.h"
#include "variables.h"
#include "recomputils.h"
#include "recompconfig.h"

#define HYPER_UPDATES recomp_get_config_u32("update_rate")

extern ActorArray *suBaddieActorArray;

bool Hyper_ShouldApply(ActorMarker *marker) {
    bool should = TRUE;

    // fake if statement as a placeholder for now
    // if (marker->id == MARKER_14_SNACKER) {
    //     should = FALSE;
    // }

    return should;
}

bool func_803296D8(Actor *this, s32 dist);

RECOMP_HOOK("func_803268B4")
void Hyper_Update(void) {
    s32 temp_v1;
    Actor *actor;
    ActorMarker *marker;
    AnimCtrl *anim_ctrl;
    // ActorInfo *actor_info;
    s32 position[3];
    s32 rotation[3];
    BKVertexList *temp_v0_3;
    bool sp54;
    s32 temp_s1;
    

    if (suBaddieActorArray != NULL) {
        sp54 = volatileFlag_get(VOLATILE_FLAG_65_CHEAT_ENTERED);
        for(temp_v1 = suBaddieActorArray->cnt - 1; temp_v1 >= 0; temp_v1--){
            actor = &suBaddieActorArray->data[temp_v1];
            // actor_info = actor->actor_info;
            marker = actor->marker;
            anim_ctrl = actor->anctrl;
            temp_s1 = actor->actor_info->unk18;
            if (marker->propPtr->unk8_4 && Hyper_ShouldApply(marker)) {
                if(sp54){ // ?
                    if (  actor->actor_info->unk20 && volatileFlag_get( actor->actor_info->unk20)) {
                        marker_despawn(marker);
                    }
                }
                if (!actor->despawn_flag) {
                    for (u32 i = 0; i < HYPER_UPDATES - 1; i++) {
                        if (marker->unk2C_2) {
                            marker->actorUpdate2Func(actor);
                            if (anim_ctrl != NULL) {
                                    actor->sound_timer = anctrl_getAnimTimer(anim_ctrl);
                            }
                        } else if (!temp_s1 || (temp_s1 && func_803296D8(actor, temp_s1))) {
                            if ( marker->actorUpdateFunc != NULL) {
                                marker->actorUpdateFunc(actor);
                                if (anim_ctrl != NULL) {
                                        actor->sound_timer = anctrl_getAnimTimer(anim_ctrl);
                                }
                            }
                        }
                    }
                    // actor->unk124_7 = TRUE;
                    // actor->unk138_28 = FALSE;
                    // if (anim_ctrl != NULL) {
                    //     anctrl_update(anim_ctrl);
                    // }
                    // if (marker->unk4C) {
                    //     temp_v0_3 = func_80330C74(actor);
                    //     if (temp_v0_3) {
                    //         func_8033F7A4(marker, temp_v0_3);
                    //         func_8034C21C(marker);
                    //     }
                    // }
                    // position[0] = (s32) actor->position[0];
                    // position[1] = (s32) actor->position[1];
                    // position[2] = (s32) actor->position[2];
                    // rotation[0] = (s32) actor->pitch;
                    // rotation[1] = (s32) actor->yaw;
                    // rotation[2] = (s32) actor->roll;
                    // func_8032F6A4(position, marker, rotation);
                    // if (actor->unk124_11) {
                    //     func_80326324(actor);
                    // }
                    // if (actor->unk148) {
                    //     if (!actor->despawn_flag) {
                    //         skeletalAnim_update(actor->unk148, time_getDelta(), marker->unk14_21);
                    //     } else {
                    //         skeletalAnim_set(actor->unk148, 0, 0.0f, 0.0f);
                    //     }
                    // }
                    // if ((actor_info->shadow_scale != 0.0f) && actor->unk124_6 && marker->unk14_21) {
                    //     func_802D7124(actor, actor_info->shadow_scale);
                    // }
                    // if (actor->is_bundle) {
                    //     actor = &suBaddieActorArray->data[temp_v1];
                    //     bundle_update(actor);
                    // }
                }
            }
        }
    }
    // if (D_8036E56C != 0) {
    //     dustEmitter_isActive(D_8036E56C);
    // }
    // if (D_8036E570 != 0) {
    //     func_802F2D8C(D_8036E570);
    // }
}