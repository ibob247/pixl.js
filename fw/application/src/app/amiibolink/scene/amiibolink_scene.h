// amiibolink_scene.h

#pragma once

#include "mini_app_registry.h"
#include "app/view/view.h"  // <-- Corrected path to view.h

typedef struct {
    mini_app_t* p_app;
    view_t* p_view;
    uint8_t amiibolink_mode;
} amiibolink_scene_t;

void amiibolink_scene_register(void);
