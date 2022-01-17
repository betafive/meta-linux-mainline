# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

SUMMARY = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

inherit kernel
inherit kernel-yocto

# The ORC unwinder is enabled in x86_64_defconfig and needs libelf-dev
DEPENDS:append:x86-64 = " elfutils-native"

DEPENDS += "xz-native bc-native"
DEPENDS:append:aarch64 = " libgcc"
KERNEL_CC:append:aarch64 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD:append:aarch64 = " ${TOOLCHAIN_OPTIONS}"

DEPENDS:append:nios2 = " libgcc"
KERNEL_CC:append:nios2 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD:append:nios2 = " ${TOOLCHAIN_OPTIONS}"

DEPENDS:append:arc = " libgcc"
KERNEL_CC:append:arc = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD:append:arc = " ${TOOLCHAIN_OPTIONS}"

# Ensure virtio block devices are supported for qemu targets
SRC_URI:append:qemuall = " file://virtio-blk.cfg"

# Enable LPAE support for 32-bit raspberrypi4
SRC_URI:append:raspberrypi4 = " file://rpi4-lpae.cfg"
