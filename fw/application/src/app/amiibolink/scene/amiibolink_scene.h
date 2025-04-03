#pragma once

#include "../../../view/view.h"
#include "../../../core/mini_app.h"

typedef struct {
    view_t* p_view;
    mini_app_t* p_app;
    int amiibolink_mode;
} amiibolink_app_t;

void amiibolink_scene_main_on_enter(amiibolink_app_t* app);
void amiibolink_scene_main_on_exit(amiibolink_app_t* app);
void amiibolink_scene_main_on_event(amiibolink_app_t* app, view_event_t event);
void amiibolink_scene_main_on_draw(amiibolink_app_t* app, canvas_t* p_canvas);

#endif
