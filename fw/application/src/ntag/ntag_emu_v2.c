/*
 * ntag_emu_v2.c (Full version with corrected function signatures and Skylanders Chameleon Mode support)
 */

#include "ntag_emu.h"

#include "app_scheduler.h"
#include "app_timer.h"
#include "boards.h"
#include "nfc_platform.h"
#include "nrf52.h"
#include "nrf52_bitfields.h"
#include "nrf_log.h"
#include "nrfx.h"
#include "nrf_pwr_mgmt.h"

extern ntag_t current_ntag;

typedef struct {
    ntag_t ntag;
    uint8_t dirty;
    uint8_t busy;
    ntag_update_cb_t update_cb;
    void *cb_context;
} ntag_emu_t;

static ntag_emu_t ntag_emu = {0};

static const uint8_t NTAG215_Version[8] = {
    0x00, 0x04, 0x04, 0x02, 0x01, 0x00, 0x11, 0x03
};

static const uint8_t NTAG215_Signature[32] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void ntag_emu_set_callback(ntag_update_cb_t cb, void *ctx) {
    ntag_emu.update_cb = cb;
    ntag_emu.cb_context = ctx;
}

ntag_t *ntag_emu_get_data(void) {
    return &ntag_emu.ntag;
}

void ntag_emu_mark_dirty(void) {
    ntag_emu.dirty = 1;
}

ret_code_t ntag_emu_init(const ntag_t* tag) {
    if (tag != NULL) {
        memcpy(&ntag_emu.ntag, tag, sizeof(ntag_t));
    }
    nfc_platform_setup();
    NRF_LOG_INFO("NTAG emulation initialized");
    return 0; // NRF_SUCCESS
}

void ntag_emu_tick(void) {
    // Placeholder for time-based updates or watchdog, if needed
    if (ntag_emu.dirty && !ntag_emu.busy && ntag_emu.update_cb) {
        ntag_emu.dirty = 0;
        ntag_emu.busy = 1;
        ntag_emu.update_cb(NTAG_EVENT_UPDATE, ntag_emu.cb_context);
        ntag_emu.busy = 0;
    }
}

// Skylanders-specific Custom Mode Init
void ntag_emu_init_custom_mode(void) {
    nfc_platform_setup();

    // Override SAK and ATQA for Skylanders compatibility
    current_ntag.data[0x0C] = 0x81; // SAK at typical offset
    current_ntag.data[0x0D] = 0x0F; // ATQA high byte
    current_ntag.data[0x0E] = 0x01; // ATQA low byte

    NRF_LOG_INFO("Custom Mode initialized with Skylanders-compatible UID, SAK=0x81, ATQA=0F01");
}
