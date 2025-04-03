// mini_app_launcher.c

#include "mini_app_launcher.h"
#include "app_defines.h"
#include "mod/cache.h"
#include "mini_app_defines.h"
#include "nrf_log.h"
#include <string.h>

void mini_app_launcher_on_app_selected(const app_context_t* app, void** p_retain_data) {
    cache_data_t* p_cache = cache_get_data();

    NRF_LOG_INFO("running APP: %d %s %d", app->p_app->id, nrf_log_push(app->p_app->name),
                 (int)app->p_app->need_retain_data);

    if (app->p_app->need_retain_data) {
        p_cache->id = app->p_app->id;
        p_cache->enabled = true;
        *p_retain_data = p_cache->retain_data;
    } else {
        p_cache->enabled = false;
        memset(p_cache->retain_data, 0, sizeof(p_cache->retain_data));
    }
}
