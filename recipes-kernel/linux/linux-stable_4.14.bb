# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "4"
LINUX_VMINOR = "14"
LINUX_VPATCH = "262"
LINUX_SHA256_TARBALL = "f81d59477e90a130857ce18dc02f4fbe5725854911db1e7ba770c7cd350f96a7"
LINUX_SHA256_PATCH = "2d7eba783a30ecb57f26171faa6a0f776c42aed5d81cf2b463e450b6e5a428f4"
require linux-stable.inc

SRC_URI += "file://4.14_0001-x86_64_defconfig-Switch-to-Frame-pointer-unwinder.patch"
