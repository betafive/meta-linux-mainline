# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "5"
LINUX_VMINOR = "10"
LINUX_VPATCH = "79"
LINUX_SHA256_TARBALL = "dcdf99e43e98330d925016985bfbc7b83c66d367b714b2de0cbbfcbf83d8ca43"
LINUX_SHA256_PATCH = "ce446196ef520362b105ec91df7c404dfde7e76564b3576faa57202a126b9bb8"
require linux-stable.inc

SRC_URI += "file://5.10_0001-kbuild-Add-KBUILD_HOSTLDFLAGS-to-has_libelf-test.patch"
