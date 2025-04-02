#ifndef NTAG_DEF_H
#define NTAG_DEF_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NTAG_DATA_SIZE 540

// Define the tag structure
typedef struct {
    uint8_t data[NTAG_DATA_SIZE];
} ntag_t;

// Define event types for tag updates
typedef enum {
    NTAG_EVENT_TYPE_READ,
    NTAG_EVENT_TYPE_UPDATE
} ntag_event_type_t;

// Callback type for tag update notifications
typedef void (*ntag_update_cb_t)(ntag_event_type_t event, void* context, const ntag_t* tag);

// Get the currently emulated tag
const ntag_t* ntag_emu_get_current_tag(void);

#ifdef __cplusplus
}
#endif

#endif // NTAG_DEF_H
