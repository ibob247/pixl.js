// amiibolink_view.c
#include "amiibolink_view.h"
#include "ntag_emu.h"
#include "mui_canvas.h"
#include "mui_element.h"
#include "ntag_def.h"  // Required for ntag_get_uid
#include <string.h>

void amiibolink_view_on_draw(mui_canvas_t *p_canvas) {
    const ntag_t *ntag = ntag_emu_get_current_tag();

    mui_canvas_clear(p_canvas);
    mui_element_text(p_canvas, 5, 5, "Amiibo Link");

    if (ntag) {
        uint8_t uid[10] = {0};
        ntag_get_uid(ntag, uid);

        char uid_str[32] = {0};
        for (int i = 0; i < 7; i++) {
            char byte_str[4];
            snprintf(byte_str, sizeof(byte_str), "%02X ", uid[i]);
            strcat(uid_str, byte_str);
        }

        mui_element_text(p_canvas, 5, 25, "UID:");
        mui_element_text(p_canvas, 40, 25, uid_str);
    } else {
        mui_element_text(p_canvas, 5, 25, "No tag loaded.");
    }
}
