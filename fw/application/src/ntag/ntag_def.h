/*
 * ntag_emu.h - Interface for NTAG emulation functions
 */

#ifndef NTAG_EMU_H
#define NTAG_EMU_H

#include "ntag_def.h"  // Central type definitions

#include <stdint.h>
#include "sdk_errors.h"  // For ret_code_t

#ifdef __cplusplus
extern "C" {
#endif

// Initialize the NTAG emulation with the given tag
ret_code_t ntag_emu_init(const ntag_t* tag);

// Set a new tag for emulation
void ntag_emu_set_tag(const ntag_t* tag);

// Set only the UUID for a tag (without affecting full data)
void ntag_emu_set_uuid_only(const ntag_t* tag);

// Get the currently emulated tag (non-const for mutation by store)
ntag_t* ntag_emu_get_current_tag(void);

// Set a callback to notify on tag update events
void ntag_emu_set_update_cb(ntag_update_cb_t cb, void* context);

#ifdef __cplusplus
}
#endif

#endif // NTAG_EMU_H
