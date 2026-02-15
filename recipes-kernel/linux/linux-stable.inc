# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require linux-mainline-common.inc
SUMMARY += "(stable)"

LINUX_STABLE_BRANCH = "linux-${LINUX_VMAJOR}.${LINUX_VMINOR}.y"
LINUX_VERSION = "${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}"
PV = "${LINUX_VERSION}"

LINUX_STABLE_GIT_URI ?= "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https"
SRC_URI = "${LINUX_STABLE_GIT_URI};branch=${LINUX_STABLE_BRANCH}"
S = "${WORKDIR}/git"
