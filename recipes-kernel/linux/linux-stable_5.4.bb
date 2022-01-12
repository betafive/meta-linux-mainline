# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "5"
LINUX_VMINOR = "4"
LINUX_VPATCH = "171"
LINUX_SHA256_TARBALL = "bf338980b1670bca287f9994b7441c2361907635879169c64ae78364efc5f491"
LINUX_SHA256_PATCH = "d28321f7f5bcd5ec96d23f995d21b5ff2071945a66a9df6dccc70eab2fee8879"
require linux-stable.inc

SRC_URI += "file://5.4_0001-kbuild-Add-KBUILD_HOSTLDFLAGS-to-has_libelf-test.patch"
