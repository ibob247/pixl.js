#pragma once

#include "mini_app.h"
#include "amiibolink_view.h"

// Scene entry point functions
void amiibolink_scene_init(mini_app_t* app);
void amiibolink_scene_on_enter(void* context);
void amiibolink_scene_on_exit(void* context);
void amiibolink_scene_on_event(void* context, const mui_event_t* p_event);

// Scene registration
extern const mui_scene_t amiibolink_scene_main;

