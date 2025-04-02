#ifndef NTAG_DEF_H
#define NTAG_DEF_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// NTAG structure definition
typedef struct {
    uint8_t data[1024];  // Full 1KB MIFARE Classic tag data
} ntag_t;

// Event types for NTAG updates
typedef enum {
    NTAG_EVENT_TYPE_READ,
    NTAG_EVENT_TYPE_UPDATE
} ntag_event_type_t;

// Callback type for NTAG updates
typedef void (*ntag_update_cb_t)(ntag_event_type_t event, void* context, const ntag_t* tag);

// Public interface to get current tag
const ntag_t* ntag_emu_get_current_tag(void);

#ifdef __cplusplus
}
#endif

#endif // NTAG_DEF_H
