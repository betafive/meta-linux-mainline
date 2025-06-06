# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

SUMMARY = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

inherit kernel kernel-yocto

KCONFIG_MODE ?= "alldefconfig"
KBUILD_DEFCONFIG ?= "defconfig"

KERNEL_EXTRA_SRC_URI ?= ""
SRC_URI:append = " ${KERNEL_EXTRA_SRC_URI}"
DEPENDS += "xz-native bc-native"

# The ORC unwinder is enabled in x86_64_defconfig and needs libelf-dev
DEPENDS:append:x86-64 = " elfutils-native"

DEPENDS:append:aarch64 = " libgcc"
KERNEL_CC:append:aarch64 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD:append:aarch64 = " ${TOOLCHAIN_OPTIONS}"

# Ensure virtio block devices are supported for qemu targets
SRC_URI:append:qemuall = " file://virtio-blk.cfg"

ERROR_QA:remove = "buildpaths"
