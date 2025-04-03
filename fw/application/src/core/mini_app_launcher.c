// mini_app_launcher.c
#include "mini_app_launcher.h"
#include "cache.h"
#include "app_manager.h"
#include "nrf_log.h"
#include <string.h>

void mini_app_launcher_run(mini_app_instance_t* app) {
    NRF_LOG_INFO("running APP: %d %s %d", app->p_app->id, nrf_log_push(app->p_app->name),
                 app->p_app->requires_retain_data);

    cache_data_t* p_cache = cache_get_data();  // ✅ Correct type now

    if (app->p_app->requires_retain_data) {
        p_cache->id = app->p_app->id;
        p_cache->enabled = true;
        app->p_retain_data = p_cache->retain_data;
    } else {
        p_cache->enabled = false;
        memset(p_cache->retain_data, 0, sizeof(p_cache->retain_data));
    }

    app->p_app->entry(app);
}
