/*
 * ntag.h - Minimal tag structure for Skylanders Chameleon Mode
 */

#ifndef NTAG_H
#define NTAG_H

#include <stdint.h>

typedef struct {
    uint8_t data[540];
} ntag_t;

#endif // NTAG_H
