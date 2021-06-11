SUMMARY = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

inherit kernel
inherit kernel-yocto

# The ORC unwinder is enabled in x86_64_defconfig and needs libelf-dev
DEPENDS_append_x86-64 = " elfutils-native"

DEPENDS += "xz-native bc-native"
DEPENDS_append_aarch64 = " libgcc"
KERNEL_CC_append_aarch64 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD_append_aarch64 = " ${TOOLCHAIN_OPTIONS}"

DEPENDS_append_nios2 = " libgcc"
KERNEL_CC_append_nios2 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD_append_nios2 = " ${TOOLCHAIN_OPTIONS}"

DEPENDS_append_arc = " libgcc"
KERNEL_CC_append_arc = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD_append_arc = " ${TOOLCHAIN_OPTIONS}"

# Ensure virtio block devices are supported for qemu targets
SRC_URI_append_qemuall = " file://virtio-blk.cfg"
