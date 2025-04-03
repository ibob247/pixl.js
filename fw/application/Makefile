PROJECT_NAME     := pixljs
SDK_ROOT         := /opt/nRF5_SDK_17.1.0_ddde560
PROJECT_ROOT     := ../..
OUTPUT_DIRECTORY := ../_build/$(PROJECT_NAME)

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

# Source files common to all targets
C_SOURCE_FILES += \
  $(wildcard src/**/*.c) \
  $(wildcard src/*.c)

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/components/ble/common \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/components/softdevice/s132/headers \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/device \
  src \
  src/view

CFLAGS += -Isrc

# Application source code path
APP_PATH := .

# Build the application
include $(TEMPLATE_PATH)/Makefile.common

