#include "amiibolink_scene_main.h"
#include "amiibolink_view.h"
#include "amiibo_helper.h"
#include "ble/ble_amiibolink.h"
#include "nfc/ntag_emu.h"
#include "core/app.h"
#include "core/app_log.h"
#include "mui/mui.h"

#include <string.h>

static void ntag_generate_cb(void* context) {
    app_t* app = (app_t*)context;
    ret_code_t err_code = amiibo_helper_rand_amiibo_uuid((ntag_t*)ntag_emu_get_current_tag());
    APP_ERROR_CHECK(err_code);
    app->dirty = true;
}

static void ntag_reload(void* context) {
    app_t* app = (app_t*)context;
    const ntag_emu_t* p_emu = ntag_emu_get();
    const ntag_t* p_ntag = ntag_emu_get_current_tag();
    const file_driver_t* p_driver = app_get_file_driver();

    char path[64];
    snprintf(path, sizeof(path), "%s.amiibo", p_emu->filename);

    ntag_t ntag;
    memset(&ntag, 0, sizeof(ntag));

    int32_t err_code = p_driver->read_file_data(path, ntag.data, NTAG_MEMORY_SIZE);
    if (err_code == 0) {
        ntag_emu_set_tag(&ntag);
    } else {
        APP_LOG_WARN("Failed to read tag data");
    }
}

static void ntag_update_cb(ntag_event_type_t type, void* context, const ntag_t* p_ntag) {
    app_t* app = (app_t*)context;
    const ntag_emu_t* p_emu = ntag_emu_get();
    const file_driver_t* p_driver = app_get_file_driver();

    if (type == NTAG_EVENT_TYPE_UPDATE && app->amiibolink_mode != BLE_AMIIBOLINK_MODE_RANDOM) {
        char path[64];
        snprintf(path, sizeof(path), "%s.amiibo", p_emu->filename);

        int32_t err_code = p_driver->write_file_data(path, p_ntag->data, NTAG_MEMORY_SIZE);
        if (err_code != 0) {
            APP_LOG_WARN("Failed to save tag data");
        }
    }

    app->dirty = true;
}

void amiibolink_scene_main_on_enter(void* context) {
    app_t* app = (app_t*)context;
    const ntag_emu_t* p_emu = ntag_emu_get();

    // Register callbacks
    ntag_emu_set_update_cb(ntag_update_cb, app);
    app->amiibolink_mode = BLE_AMIIBOLINK_MODE_DEFAULT;

    // Auto-generate if needed
    if (p_emu->autogen) {
        ntag_generate_cb(app);
    } else {
        ntag_reload(app);
    }

    // Update BLE tag
    ble_amiibolink_set_tag(ntag_emu_get_current_tag());

    // Set the view
    app_view_set_handler(app, amiibolink_view_on_draw);
}
