// main.c
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "cache.h"
#include "ntag_emu.h"

static void initialize_ntag_from_cache(void) {
    cache_data_t* p_cache = cache_get_data();

    if (p_cache && p_cache->ntag.data[0] != 0x00) {
        ntag_emu_set_tag(&p_cache->ntag);
    }
}

int main(void) {
    NRF_LOG_INIT(NULL);
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    initialize_ntag_from_cache();

    while (true) {
        NRF_LOG_FLUSH();
    }
}
