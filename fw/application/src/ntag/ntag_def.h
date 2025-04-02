#ifndef NTAG_DEF_H
#define NTAG_DEF_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Size of the NTAG memory (e.g., 540 bytes for NTAG215)
#define NTAG_MEMORY_SIZE 540

// Event types for NTAG updates
typedef enum {
    NTAG_EVENT_TYPE_READ,
    NTAG_EVENT_TYPE_UPDATE
} ntag_event_type_t;

// Structure representing an NTAG
typedef struct {
    uint8_t data[NTAG_MEMORY_SIZE];
} ntag_t;

// Callback type for NTAG updates
typedef void (*ntag_update_cb_t)(ntag_event_type_t event, void* context, const ntag_t* tag);

// Gets the current tag being emulated
const ntag_t* ntag_emu_get_current_tag(void);

#ifdef __cplusplus
}
#endif

#endif // NTAG_DEF_H
