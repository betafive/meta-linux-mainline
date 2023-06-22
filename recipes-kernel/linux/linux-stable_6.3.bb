# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "6"
LINUX_VMINOR = "3"
LINUX_VPATCH = "9"
LINUX_SHA256_TARBALL = "ba3491f5ed6bd270a370c440434e3d69085fcdd528922fa01e73d7657db73b1e"
LINUX_SHA256_PATCH = "d12ae712a4bd2cfb99cf368b246562e54bf6ca0bafd46a91e25faf34077c6587"
require linux-stable.inc

SRC_URI += "file://20230117_arnd_workqueue_fix_enum_type_for_gcc_13.patch"
