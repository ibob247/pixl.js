// cache.h
#ifndef CACHE_H
#define CACHE_H

#include "ntag_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ntag_t ntag;
} mod_cache_t;

mod_cache_t* mod_cache_get_data(void);

#ifdef __cplusplus
}
#endif

#endif // CACHE_H
