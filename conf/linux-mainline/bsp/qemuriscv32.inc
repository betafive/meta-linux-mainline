# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

KBUILD_DEFCONFIG = "rv32_defconfig"
KCONFIG_MODE = "alldefconfig"

python __anonymous() {
    # Make sure that the selected kernel version supports the target machine
    machine = d.getVar("MACHINE")
    if d.getVar("PN") == "linux-stable":
        vmajor = int(d.getVar("LINUX_VMAJOR"))
        vminor = int(d.getVar("LINUX_VMINOR"))
        if (vmajor, vminor) < (5, 10):
            msg = "Skipping linux-stable recipe (from meta-linux-mainline) as it is too old to support %s" % (machine)
            raise bb.parse.SkipRecipe(msg)
}
