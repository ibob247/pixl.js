# NRF5 SDK bootloader Makefile for Pixl.js

TARGET = bootloader
BOARD = pixljs
TEMPLATE_PATH = ../../components/toolchain/gcc
PROJ_DIR = .

# Source files common to all targets
C_SOURCE_FILES += \
  $(PROJ_DIR)/main.c \
  $(PROJ_DIR)/lcd_comm.c \
  $(PROJ_DIR)/lcd_drv.c \
  $(PROJ_DIR)/dfu_public_key.c \
  $(PROJ_DIR)/nrf_bootloader.c \
  $(PROJ_DIR)/nrf_bootloader_app_start.c \
  $(PROJ_DIR)/nrf_bootloader_app_start_final.c \
  $(PROJ_DIR)/nrf_bootloader_dfu_timers.c \
  $(PROJ_DIR)/nrf_bootloader_fw_activation.c \
  $(PROJ_DIR)/nrf_bootloader_info.c \
  $(PROJ_DIR)/nrf_bootloader_wdt.c \
  $(PROJ_DIR)/nrf_dfu.c \
  $(PROJ_DIR)/nrf_dfu_ble.c \
  $(PROJ_DIR)/nrf_dfu_flash.c \
  $(PROJ_DIR)/nrf_dfu_handling_error.c \
  $(PROJ_DIR)/nrf_dfu_mbr.c \
  $(PROJ_DIR)/nrf_dfu_req_handler.c \
  $(PROJ_DIR)/nrf_dfu_settings.c \
  $(PROJ_DIR)/nrf_dfu_settings_svci.c \
  $(PROJ_DIR)/nrf_dfu_svci.c \
  $(PROJ_DIR)/nrf_dfu_svci_handler.c \
  $(PROJ_DIR)/nrf_dfu_transport.c \
  $(PROJ_DIR)/nrf_dfu_utils.c \
  $(PROJ_DIR)/nrf_dfu_validation.c \
  $(PROJ_DIR)/nrf_dfu_ver_validation.c \
  $(PROJ_DIR)/nrf_sdh.c \
  $(PROJ_DIR)/nrf_sdh_ble.c \
  $(PROJ_DIR)/nrf_sdh_soc.c \
  $(PROJ_DIR)/nrf_svc_handler.c \
  $(PROJ_DIR)/pb_common.c \
  $(PROJ_DIR)/pb_decode.c \
  $(PROJ_DIR)/dfu-cc.pb.c \
  $(PROJ_DIR)/oberon_backend_chacha_poly_aead.c \
  $(PROJ_DIR)/oberon_backend_ecc.c \
  $(PROJ_DIR)/oberon_backend_ecdh.c \
  $(PROJ_DIR)/oberon_backend_ecdsa.c \
  $(PROJ_DIR)/oberon_backend_eddsa.c \
  $(PROJ_DIR)/oberon_backend_hash.c \
  $(PROJ_DIR)/oberon_backend_hmac.c \
  $(PROJ_DIR)/nrf_sw_backend_hash.c

# Include paths common to all targets
INC_PATHS += -I$(PROJ_DIR)

# C flags common to all targets
CFLAGS += -DBOARD_$(BOARD)

# Use relative path to Makefile.common
include ../../components/toolchain/gcc/Makefile.common
