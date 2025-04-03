#pragma once

#include "ble/ble_amiibolink_types.h"
#include "ntag/ntag_def.h"

// Forward declaration of the app data structure
typedef struct {
    ble_amiibolink_mode_t amiibolink_mode;
    bool show_animation;
} amiibolink_scene_main_data_t;

// Callback when an NTAG event occurs
void ntag_update_cb(ntag_event_type_t type, void* context, const ntag_t* p_ntag);

// Entry point when the scene is entered
void amiibolink_scene_main_on_enter(void* context);

// Called periodically to update scene state
bool amiibolink_scene_main_on_update(void* context);

// Called when an input is received
bool amiibolink_scene_main_on_event(void* context, const void* event);

// Called before the scene is exited
void amiibolink_scene_main_on_exit(void* context);

