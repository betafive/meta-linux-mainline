# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

KERNEL_DEVICETREE = "bcm2711-rpi-4-b.dtb"
RPI_EXTRA_CONFIG += " \
    upstream_kernel=1 \n \
    avoid_warnings=2 \n"

CMDLINE_ROOTFS = "root=/dev/mmcblk1p2 rootfstype=ext4 rootwait"

KBUILD_DEFCONFIG = "multi_v7_defconfig"
KCONFIG_MODE = "alldefconfig"
DISABLE_VC4GRAPHICS = "1"
require conf/linux-mainline/bsp/rpi-overrides-${LINUX_MAINLINE_OVERRIDE_SYNTAX}.inc

do_image_wic[depends] += "rpi-cmdline:do_deploy"

python __anonymous() {
    # Make sure that the selected kernel version supports the target machine
    machine = d.getVar("MACHINE")
    if d.getVar("PN") == "linux-stable" and "raspberrypi4" in machine:
        vmajor = int(d.getVar("LINUX_VMAJOR"))
        vminor = int(d.getVar("LINUX_VMINOR"))
        if (vmajor, vminor) < (5, 10):
            msg = "Skipping linux-stable recipe (from meta-linux-mainline) as it is too old to support %s" % (machine)
            raise bb.parse.SkipRecipe(msg)
}
