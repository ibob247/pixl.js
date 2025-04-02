#ifndef NTAG_EMU_H
#define NTAG_EMU_H

#include "ntag_def.h"

#ifdef __cplusplus
extern "C" {
#endif

// Initializes the NTAG emulator with a tag
ret_code_t ntag_emu_init(const ntag_t* tag);

// Sets the current tag for emulation
void ntag_emu_set_tag(const ntag_t* tag);

// Sets the UUID of the current tag only
void ntag_emu_set_uuid_only(const ntag_t* tag);

// Gets the current tag being emulated
const ntag_t* ntag_emu_get_current_tag(void);

// Sets a callback for when the tag changes
void ntag_emu_set_callback(ntag_update_cb_t callback, void* context);

#ifdef __cplusplus
}
#endif

#endif // NTAG_EMU_H
