#ifndef NTAG_STORE_H
#define NTAG_STORE_H

#include <stdint.h>
#include <stdbool.h>
#include "ntag.h"
#include "nrf_error.h" // For ret_code_t

bool ntag_store_load_from_dump(const char* path);
ret_code_t ntag_store_uuid_rand(ntag_t *ntag);
ret_code_t ntag_store_new_rand(ntag_t *ntag);
void ntag_store_get_uuid(ntag_t *ntag, uint8_t *uuid);
void ntag_store_set_uuid(ntag_t *ntag, uint8_t *uuid);

#endif // NTAG_STORE_H
