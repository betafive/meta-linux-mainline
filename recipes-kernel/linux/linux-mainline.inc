# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require linux-mainline-common.inc
SUMMARY += "(mainline)"

PV = "${LINUX_VERSION}"

LINUX_MAINLINE_GIT_URI ?= "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRC_URI = "${LINUX_MAINLINE_GIT_URI};branch=master"
S = "${WORKDIR}/git"

DEPENDS += "libyaml-native python3-dtschema-wrapper-native"
inherit pkgconfig

do_compile:prepend() {
	# setup native pkg-config variables (kconfig scripts call pkg-config directly, cannot generically be overriden to pkg-config-native)
	export PKG_CONFIG_DIR="${STAGING_DIR_NATIVE}${libdir_native}/pkgconfig"
	export PKG_CONFIG_PATH="$PKG_CONFIG_DIR:${STAGING_DATADIR_NATIVE}/pkgconfig"
	export PKG_CONFIG_LIBDIR="$PKG_CONFIG_DIR"
	export PKG_CONFIG_SYSROOT_DIR=""
}
