// amiibolink_view.c
#include "amiibolink_view.h"
#include "ntag_emu.h"
#include "mui_canvas.h"
#include "mui_element.h"
#include <string.h>

void amiibolink_view_on_draw(mui_canvas_t *p_canvas) {
    ntag_t *ntag = (ntag_t *)ntag_emu_get_current_tag(); // Cast to suppress const warning

    mui_canvas_clear(p_canvas);
    mui_element_text(p_canvas, 5, 5, "Amiibo Link");

    if (ntag) {
        char uid_str[32] = {0};
        for (int i = 0; i < 7; i++) {
            char byte_str[4];
            snprintf(byte_str, sizeof(byte_str), "%02X ", ntag->uid[i]);
            strcat(uid_str, byte_str);
        }
        mui_element_text(p_canvas, 5, 25, "UID:");
        mui_element_text(p_canvas, 40, 25, uid_str);

        // Removed ntag->notes rendering for safety
    } else {
        mui_element_text(p_canvas, 5, 25, "No tag loaded.");
    }
}
