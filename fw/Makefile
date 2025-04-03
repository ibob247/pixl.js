# Root Makefile for firmware build system

APP_VERSION ?= dev
BOARD ?= OLED

APP_DIR := application
BOOTLOADER_DIR := bootloader
BUILD_DIR := _build

.PHONY: all app bootloader clean ota

all: bootloader app

bootloader:
	$(MAKE) -C $(BOOTLOADER_DIR) RELEASE=1 APP_VERSION=$(APP_VERSION) BOARD=$(BOARD)

app:
	$(MAKE) -C $(APP_DIR) RELEASE=1 APP_VERSION=$(APP_VERSION) BOARD=$(BOARD)

# Add src/ to include paths globally (in case some headers rely on it)
export CFLAGS += -Isrc

# Optional OTA step (customize as needed)
ota:
	@echo "Packaging OTA update... (customize this rule if needed)"

clean:
	$(MAKE) -C $(BOOTLOADER_DIR) clean
	$(MAKE) -C $(APP_DIR) clean
	rm -rf $(BUILD_DIR)
