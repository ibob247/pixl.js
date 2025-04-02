/*
 * main.c - Entry point for firmware logic
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "app_error.h"
#include "nrf_log.h"
#include "nrf_pwr_mgmt.h"
#include "ntag_emu.h"
#include "ntag_store.h"
#include "amiibo_helper.h"
#include "mod/cache.h"

// Forward declarations
void shutdown_handler(void);
void check_wakeup_src(void);

// Simulated default NTAG215 structure
const ntag_t default_ntag215 = {
    .data = {0x00} // Fill with zeros for now
};

void shutdown_handler(void) {
    NRF_LOG_INFO("Shutting down. Saving current tag state to cache.");
    mod_cache_t* p_cache_data = mod_cache_get_data();
    if (p_cache_data) {
        memcpy(&p_cache_data->ntag, ntag_emu_get_current_tag(), sizeof(ntag_t));
    }
}

void check_wakeup_src(void) {
    hal_nfc_set_nrfx_irq_enable(true);

    mod_cache_t* p_cache = mod_cache_get_data();
    if (p_cache && p_cache->ntag.data[0] != 0x00) {
        NRF_LOG_INFO("Restoring NTAG state from cache.");
        ntag_emu_set_tag(&p_cache->ntag);
    } else {
        NRF_LOG_INFO("No cached tag found. Loading default NTAG215.");
        ret_code_t err_code = ntag_emu_init(&default_ntag215);
        APP_ERROR_CHECK(err_code);
    }
}

int main(void) {
    NRF_LOG_INIT(NULL);
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    check_wakeup_src();

    while (true) {
        NRF_LOG_FLUSH();
        nrf_pwr_mgmt_run();
    }
    return 0;
}
