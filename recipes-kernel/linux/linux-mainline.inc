# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require linux-mainline-common.inc
SUMMARY += "(mainline)"

PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
S = "${WORKDIR}/git"

# The version of kconfiglib used in the gatesgarth & hardknott branches does
# not correctly parse Kconfig files of Linux v5.13
python __anonymous() {
    if d.getVar("LAYERSERIES_CORENAMES") in ("gatesgarth", "hardknott"):
        d.setVar("KERNEL_CONFIGCHECK_SKIPPED", "1")
}

do_kernel_configcheck_prepend() {
    if d.getVar("KERNEL_CONFIGCHECK_SKIPPED") == "1":
        bb.warn("Skipping kernel_configcheck for Linux 5.13 or later on gatesgarth & hardknott Yocto releases")
        return
}
