# Bootloader Makefile for Pixl.js
APP_NAME := bootloader

SDK_ROOT := ../../nRF5_SDK_17.1.0_ddde560
TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc
MAKEFILE_NAME := Makefile
MAKEFILE_COMMON := $(TEMPLATE_PATH)/Makefile.common

PROJECT_DIR := .
BUILD_DIR := ../_build/$(APP_NAME)

SRC_FILES := \
  main.c \
  lcd_comm.c \
  lcd_drv.c \
  dfu_public_key.c \
  $(wildcard $(SDK_ROOT)/components/**/*.c)

INC_PATHS := \
  -I. \
  -I$(SDK_ROOT)/components \
  -I$(SDK_ROOT)/components/libraries/bootloader \
  -I$(SDK_ROOT)/components/libraries/util \
  -I$(SDK_ROOT)/components/libraries/log \
  -I$(SDK_ROOT)/modules/nrfx/mdk \
  -I$(SDK_ROOT)/components/toolchain/cmsis/include \
  -I$(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd \
  -Isrc

CFLAGS += $(INC_PATHS)

# Include Nordic SDK build rules
include $(MAKEFILE_COMMON)
