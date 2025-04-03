// cache.c
#include "cache.h"
#include <string.h>

static mod_cache_t g_cache_data;

mod_cache_t* cache_get_data(void) {
    return &g_cache_data;
}
