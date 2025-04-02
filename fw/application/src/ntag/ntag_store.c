/*
 * ntag_store.c - Implementation for Skylanders Chameleon Mode
 */

#include "ntag_store.h"
#include "ntag_emu.h"
#include "emulator_settings.h"
#include "ff.h"
#include "nrf_log.h"
#include <string.h>

static ntag_update_cb_t emu_callback = NULL;
static void* emu_context = NULL;
static ntag_t current_tag;

bool ntag_store_load_from_dump(const char* path) {
    FIL file;
    UINT bytes_read;

    if (f_open(&file, path, FA_READ) != FR_OK) return false;

    f_read(&file, current_tag.data, sizeof(current_tag.data), &bytes_read);
    f_close(&file);

    if (bytes_read != sizeof(current_tag.data)) return false;

    if (emu_callback) emu_callback(NTAG_EVENT_TYPE_UPDATE, emu_context);

    if (emu_callback) {
        uint8_t* uid = &current_tag.data[0];
        NRF_LOG_INFO("Preserving UID from dump: %02X %02X %02X %02X %02X %02X %02X",
                     uid[0], uid[1], uid[2], uid[3], uid[4], uid[5], uid[6]);
    }

    return true;
}

int ntag_store_uuid_rand(ntag_t *ntag) {
    // Generate 7-byte random UID
    for (int i = 0; i < 7; ++i)
        ntag->data[i] = (uint8_t)(rand() & 0xFF);

    return 0; // Success
}

int ntag_store_new_rand(ntag_t *ntag) {
    return ntag_store_uuid_rand(ntag);
}

void ntag_store_get_uuid(ntag_t *ntag, uint8_t *uuid) {
    memcpy(uuid, &ntag->data[0], 7);
}

void ntag_store_set_uuid(ntag_t *ntag, uint8_t *uuid) {
    memcpy(&ntag->data[0], uuid, 7);
}

void ntag_emu_set_update_cb(ntag_update_cb_t cb, void* context) {
    emu_callback = cb;
    emu_context = context;
}
