// ntag_emu.h
#ifndef NTAG_EMU_H
#define NTAG_EMU_H

#include "ntag_def.h"

#ifdef __cplusplus
extern "C" {
#endif

void ntag_emu_set_tag(const ntag_t* tag);
void ntag_emu_set_uuid_only(const ntag_t* ntag);
void ntag_emu_set_update_cb(ntag_update_cb_t cb, void* context);

#ifdef __cplusplus
}
#endif

#endif // NTAG_EMU_H
