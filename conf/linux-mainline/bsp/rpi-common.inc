# Copyright (C) meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

RPI_EXTRA_CONFIG += " \
    upstream_kernel=1 \n \
    avoid_warnings=2 \n"
CMDLINE_ROOTFS = "root=/dev/mmcblk1p2 rootfstype=ext4 rootwait"
KCONFIG_MODE = "alldefconfig"
DISABLE_VC4GRAPHICS = "1"
DISTRO_FEATURES:remove = "opengl x11 wayland vulkan"

do_image_wic[depends] += "rpi-cmdline:do_deploy"

python __anonymous() {
    if d.getVar("PN") == "linux-stable":
        kver = (int(d.getVar("LINUX_VMAJOR")), int(d.getVar("LINUX_VMINOR")))

        # Make sure that the selected kernel version supports the target machine
        if kver < (5, 10):
            machine = d.getVar("MACHINE")
            msg = "Skipping linux-stable recipe (from meta-linux-mainline) as it is too old to support %s" % (machine)
            raise bb.parse.SkipRecipe(msg)
}
