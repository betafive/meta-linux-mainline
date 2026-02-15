# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

RV32_CONFIG_FRAGMENTS = " \
    file://rv32.cfg \
    file://nonportable.cfg \
"

KERNEL_EXTRA_SRC_URI += "${RV32_CONFIG_FRAGMENTS}"

python __anonymous() {
    if d.getVar("PN") == "linux-stable":
        kver = (int(d.getVar("LINUX_VMAJOR")), int(d.getVar("LINUX_VMINOR")))

        # Prior to v5.16, RV32 used a separate 'rv32_defconfig' file
        # From v5.16 to v6.0, RV32 did not set CONFIG_NONPORTABLE
        if kver < (5, 16):
            d.setVar("RV32_CONFIG_FRAGMENTS", "")
            d.setVar("KBUILD_DEFCONFIG", "rv32_defconfig")
        elif kver < (6, 0):
            d.setVar("RV32_CONFIG_FRAGMENTS", "file://rv32.cfg")
}
