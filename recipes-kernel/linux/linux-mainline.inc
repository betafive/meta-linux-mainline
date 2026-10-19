# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require linux-mainline-common.inc
SUMMARY += "(mainline)"

PV = "${LINUX_VERSION}"

LINUX_MAINLINE_GIT_URI ?= "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRC_URI = "${LINUX_MAINLINE_GIT_URI};branch=master"
