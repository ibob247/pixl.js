/*
 * ntag_store.c (Finalized for Skylanders Chameleon Mode)
 */

#include <stdio.h>
#include <string.h>
#include "ntag_store.h"
#include "nrf_log.h"
#include "utils2.h"
#include "vfs.h"
#include "ntag_emu.h"

ntag_t current_ntag;

const ntag_t default_ntag215 = {
    .data = {0x04, 0x68, 0x95, 0x71, 0xfa, 0x5c, 0x64, 0x80, 0x42, 0x48, 0x00, 0x00, 0xe1, 0x10, 0x3e, 0x00, 0x03,
             0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x10, 0xff, 0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

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
        NRF_LOG_ERROR("Dump file too small (%u bytes)", bytesRead);
        return false;
    }

    // Extract UID from dump (first 7 bytes of block 0)
    NRF_LOG_INFO("Preserving UID from dump: %02X %02X %02X %02X %02X %02X %02X",
        current_ntag.data[0], current_ntag.data[1], current_ntag.data[2],
        current_ntag.data[3], current_ntag.data[4], current_ntag.data[5],
        current_ntag.data[6]);

    // Override SAK and ATQA (Skylanders standard)
    current_ntag.data[0x0C] = 0x81; // SAK
    current_ntag.data[0x0D] = 0x0F; // ATQA high byte
    current_ntag.data[0x0E] = 0x01; // ATQA low byte

    return true;
}

// STUB: Generate a random UID for the tag
ret_code_t ntag_store_uuid_rand(ntag_t *ntag) {
    static uint8_t fallback_uid[7] = {0x04, 0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
    memcpy(ntag->data, fallback_uid, 7);
    return 0; // NRF_SUCCESS
}

// STUB: Copy UUID from ntag data
void ntag_store_get_uuid(ntag_t *ntag, uint8_t *uuid) {
    memcpy(uuid, ntag->data, 7);
}

// Alias to support expected external function
ret_code_t ntag_store_new_rand(ntag_t *ntag) {
    return ntag_store_uuid_rand(ntag);
}

// STUB: Set UUID into tag
void ntag_store_set_uuid(ntag_t *ntag, uint8_t *uuid) {
    if (ntag && uuid) {
        memcpy(ntag->data, uuid, 7);
    }
}

// --- Required ntag_emu.h stubs for build compatibility ---

static ntag_update_cb_t emu_callback = NULL;
static void* emu_context = NULL;

void ntag_emu_set_update_cb(ntag_update_cb_t cb, void* context) {
    emu_callback = cb;
    emu_context = context;
}

void ntag_emu_set_tag(const ntag_t* tag) {
    if (tag) memcpy(&current_ntag, tag, sizeof(ntag_t));
}

ntag_t* ntag_emu_get_current_tag() {
    return &current_ntag;
}

// Placeholder for setting only the UUID
void ntag_emu_set_uuid_only(const ntag_t* ntag) {
    if (ntag) {
        memcpy(current_ntag.data, ntag->data, 7);
    }
}
