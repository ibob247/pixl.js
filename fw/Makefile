BOARD ?= LCD
APP_VERSION ?= dev
RELEASE ?= 0

BUILD_DIR := _build
BUILD_TARGET := pixljs
BUILD_OUTPUT := $(BUILD_DIR)/$(BUILD_TARGET).hex
ALL_OUTPUT := $(BUILD_DIR)/$(BUILD_TARGET)_all.hex
OTA_ZIP := $(BUILD_DIR)/pixjs_ota_v$(APP_VERSION).zip

.PHONY: all firmware ota full clean

all:
	@echo "=== Building firmware for $(BOARD) ==="
	$(MAKE) -C bootloader
	$(MAKE) -C application BOARD=$(BOARD) RELEASE=$(RELEASE) APP_VERSION=$(APP_VERSION)

firmware:
	@echo "=== Copying firmware hex to $(BUILD_OUTPUT) ==="
	cp $(BUILD_DIR)/$(BUILD_TARGET)_$(BOARD).hex $(BUILD_OUTPUT)

ota:
	@echo "=== Packaging OTA firmware ==="
	@mkdir -p $(BUILD_DIR)
	zip -j -6 $(OTA_ZIP) $(BUILD_OUTPUT)

full: all firmware ota

clean:
	@echo "=== Cleaning all builds ==="
	$(MAKE) -C bootloader clean
	$(MAKE) -C application clean
	rm -rf $(BUILD_DIR)
