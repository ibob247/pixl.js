/*
 * ntag_def.h - Definitions for NTAG emulation
 */

#ifndef NTAG_DEF_H
#define NTAG_DEF_H

#include <stdint.h>

// NTAG event types
typedef enum {
    NTAG_EVENT_TYPE_NONE = 0,
    NTAG_EVENT_TYPE_READ,
    NTAG_EVENT_TYPE_UPDATE
} ntag_event_type_t;

// NTAG structure (basic representation)
typedef struct {
    uint8_t data[540];  // Typical NTAG215 size (504 bytes), extended for safety
} ntag_t;

// Callback type for NTAG emulation updates
typedef void (*ntag_update_cb_t)(ntag_event_type_t event, void* context, const ntag_t* tag);

#endif // NTAG_DEF_H
