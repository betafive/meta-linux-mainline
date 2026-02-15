# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require conf/linux-mainline/bsp/rpi-common.inc

KERNEL_EXTRA_SRC_URI += "file://rpi4-lpae.cfg"
KERNEL_DEVICETREE = "broadcom/bcm2711-rpi-4-b.dtb"
KBUILD_DEFCONFIG = "multi_v7_defconfig"

python __anonymous() {
    # Make sure that the selected kernel version supports the target machine
    if d.getVar("PN") == "linux-stable":
        kver = (int(d.getVar("LINUX_VMAJOR")), int(d.getVar("LINUX_VMINOR")))

        # Device tree files for ARM32 were moved into subdirectories in v6.5
        if kver < (6, 5):
            d.setVar("KERNEL_DEVICETREE", "bcm2711-rpi-4-b.dtb")
}
