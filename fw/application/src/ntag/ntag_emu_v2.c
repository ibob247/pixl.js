/*
 * t2t_emu.c (Modified for Skylanders Chameleon Mode)
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
#include "hal_nfc_t2t.h"

extern ntag_t current_ntag; // ensure we access the current tag buffer

// Skylanders-specific Custom Mode Init
void ntag_emu_init_custom_mode(void) {
    // Set UID from loaded tag, do not generate
    nfc_platform_setup(current_ntag.data, 7); // UID length is 7 bytes

    // Override SAK and ATQA for Skylanders compatibility
    current_ntag.data[0x0C] = 0x81; // SAK at typical offset (might vary)
    current_ntag.data[0x0D] = 0x0F; // ATQA (0F)
    current_ntag.data[0x0E] = 0x01; // ATQA (01)

    NRF_LOG_INFO("Custom Mode initialized with Skylanders-compatible UID, SAK=0x81, ATQA=0F01");
    // Start emulation using loaded tag
    hal_nfc_t2t_emulation_start(current_ntag.data, sizeof(current_ntag.data));
}

/*
 * ntag_store.c (Modified for Skylanders Chameleon Mode)
 */

#include "ntag_store.h"
#include "nrf_log.h"
#include "utils2.h"
#include "vfs.h"

ntag_t current_ntag;

bool ntag_store_load_from_dump(const char* path) {
    NRF_LOG_INFO("Loading Skylander dump from: %s", path);

    FILE* f = fopen(path, "rb");
    if (!f) {
        NRF_LOG_ERROR("Failed to open file");
        return false;
    }

    size_t bytesRead = fread(current_ntag.data, 1, sizeof(current_ntag.data), f);
    fclose(f);

    if (bytesRead < 540) {
        NRF_LOG_ERROR("Dump file too small");
        return false;
    }

    // Extract UID from dump (first 7 bytes of block 0)
    NRF_LOG_INFO("Preserving UID from dump: %02X %02X %02X %02X %02X %02X %02X",
        current_ntag.data[0], current_ntag.data[1], current_ntag.data[2],
        current_ntag.data[3], current_ntag.data[4], current_ntag.data[5],
        current_ntag.data[6]);

    // Override ATQA and SAK (Skylanders standard)
    current_ntag.data[0x0C] = 0x81; // SAK
    current_ntag.data[0x0D] = 0x0F; // ATQA
    current_ntag.data[0x0E] = 0x01; // ATQA

    return true;
}
