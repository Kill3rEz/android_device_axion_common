AXION_COMMON_PATH := device/axion/common
AXION_COMMON_MODULE_ROOT := $(AXION_COMMON_PATH)/kernel/modules

AXION_COMMON_KERNEL_MODULES := \
    ax_dragonite

ifneq ($(strip $(TARGET_KERNEL_SOURCE)),)
ifeq ($(strip $(TARGET_PREBUILT_KERNEL)),)
ifneq ($(wildcard $(TARGET_KERNEL_SOURCE)/Makefile),)
AXION_COMMON_KERNEL_VERSION := $(shell awk \
    '/^VERSION =/{version=$$3} /^PATCHLEVEL =/{patch=$$3} END{if (version && patch) print version "." patch}' \
    $(TARGET_KERNEL_SOURCE)/Makefile)
AXION_COMMON_KERNEL_MAJOR := $(firstword $(subst ., ,$(AXION_COMMON_KERNEL_VERSION)))

ifeq ($(strip $(TARGET_KERNEL_EXT_MODULE_ROOT)),)
TARGET_KERNEL_EXT_MODULE_ROOT := $(AXION_COMMON_MODULE_ROOT)
endif

ifeq ($(TARGET_KERNEL_EXT_MODULE_ROOT),$(AXION_COMMON_MODULE_ROOT))
TARGET_KERNEL_EXT_MODULES += $(foreach module,$(AXION_COMMON_KERNEL_MODULES),$(module):kbuild)
endif
endif
endif
endif
