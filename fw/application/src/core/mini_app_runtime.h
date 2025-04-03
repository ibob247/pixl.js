// mini_app_runtime.h
#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t id;
    const char* name;
    bool (*run)(void* context);
} mini_app_def_t;

typedef struct {
    const mini_app_def_t* p_app;
    void* p_retain_data;
} mini_app_runtime_t;
