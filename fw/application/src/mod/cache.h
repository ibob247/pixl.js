// cache.h
#ifndef CACHE_H
#define CACHE_H

#include <stdint.h>
#include <stdbool.h>
#include "ntag_def.h"

// Define the retain data structure
typedef struct {
    uint32_t id;
    bool enabled;
    uint8_t retain_data[128]; // Adjust size as needed for retainable app state
    ntag_t ntag;
} cache_data_t;

// Function to get access to the cache
cache_data_t* cache_get_data(void);

#endif // CACHE_H
