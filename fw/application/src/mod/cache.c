// cache.c
#include "mod/cache.h"
#include <string.h>

// Static instance of the cache structure
static mod_cache_t m_cache;

mod_cache_t* mod_cache_get_data(void) {
    return &m_cache;
}

void mod_cache_init(void) {
    memset(&m_cache, 0, sizeof(m_cache));
    m_cache.enabled = false;
    m_cache.id = -1; // Default invalid ID
}

void mod_cache_set_id(int id) {
    m_cache.id = id;
}

int mod_cache_get_id(void) {
    return m_cache.id;
}

void mod_cache_enable(bool enable) {
    m_cache.enabled = enable;
}

bool mod_cache_is_enabled(void) {
    return m_cache.enabled;
}

void mod_cache_set_retain_data(const uint8_t* data, size_t len) {
    if (len > sizeof(m_cache.retain_data)) len = sizeof(m_cache.retain_data);
    memcpy(m_cache.retain_data, data, len);
}

const uint8_t* mod_cache_get_retain_data(void) {
    return m_cache.retain_data;
}
