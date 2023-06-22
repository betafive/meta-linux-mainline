# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "6"
LINUX_VMINOR = "1"
LINUX_VPATCH = "35"
LINUX_SHA256_TARBALL = "2ca1f17051a430f6fed1196e4952717507171acfd97d96577212502703b25deb"
LINUX_SHA256_PATCH = "d838506aa063b8e41aeaf2372d1332725f9b5db8a334121c7ee626dfc40688c5"
require linux-stable.inc

SRC_URI += "file://20230117_arnd_workqueue_fix_enum_type_for_gcc_13.patch"
