// cache.c
#include "cache.h"
#include <string.h>

static cache_data_t g_cache_data;

cache_data_t* cache_get_data(void) {
    return &g_cache_data;
}
