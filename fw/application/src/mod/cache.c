// cache.c
#include "cache.h"

// Simple static cache storage
static mod_cache_t mod_cache_data;

mod_cache_t* mod_cache_get_data(void) {
    return &mod_cache_data;
}
