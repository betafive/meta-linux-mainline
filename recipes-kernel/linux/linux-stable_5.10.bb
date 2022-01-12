# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VMAJOR = "5"
LINUX_VMINOR = "10"
LINUX_VPATCH = "91"
LINUX_SHA256_TARBALL = "dcdf99e43e98330d925016985bfbc7b83c66d367b714b2de0cbbfcbf83d8ca43"
LINUX_SHA256_PATCH = "de26ebfe8d9db3e190361b2ed7c5779a0ce19c51bbbd8c39cecd5b4922b5c959"
require linux-stable.inc

SRC_URI += "file://5.10_0001-kbuild-Add-KBUILD_HOSTLDFLAGS-to-has_libelf-test.patch"
