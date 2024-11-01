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
