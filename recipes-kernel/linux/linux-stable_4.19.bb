# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "4"
LINUX_VMINOR = "19"
LINUX_VPATCH = "225"
LINUX_SHA256_TARBALL = "0c68f5655528aed4f99dae71a5b259edc93239fa899e2df79c055275c21749a1"
LINUX_SHA256_PATCH = "350441955d846886eedd03003b65ac6d21288991a85ec971072e9126fb901dd0"
require linux-stable.inc

SRC_URI += "file://4.19_0001-kbuild-Add-KBUILD_HOSTLDFLAGS-to-has_libelf-test.patch"
