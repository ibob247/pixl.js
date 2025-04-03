// cache.c
#include "cache.h"
#include <string.h>

static cache_data_t g_cache_data = {
    .id = 0,
    .enabled = false,
    .retain_data = {0},
    .ntag = {0}
};

cache_data_t* cache_get_data(void) {
    return &g_cache_data;
}
