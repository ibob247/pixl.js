// mini_app_launcher.c
#include "mini_app_launcher.h"
#include "mini_app_runtime.h"
#include "mini_app_defines.h"
#include "cache.h"
#include <string.h>
#include <stdbool.h>
#include <nrf_log.h>

void mini_app_launch(mini_app_runtime_t* app) {
    NRF_LOG_INFO("running APP: %d %s %d",
        app->p_app->id,
        nrf_log_push(app->p_app->name),
        app->p_app->run != NULL
    );

    cache_data_t* p_cache = cache_get_data();

    if (app->p_app->run) {
        p_cache->id = app->p_app->id;
        p_cache->enabled = true;
        app->p_retain_data = p_cache->retain_data;

        bool keep_running = app->p_app->run(app->p_retain_data);
        if (!keep_running) {
            p_cache->enabled = false;
            memset(p_cache->retain_data, 0, sizeof(p_cache->retain_data));
        }
    } else {
        p_cache->enabled = false;
        memset(p_cache->retain_data, 0, sizeof(p_cache->retain_data));
    }
}
