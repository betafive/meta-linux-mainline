# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require linux-mainline-common.inc
SUMMARY += "(stable)"

LINUX_STABLE_BRANCH = "linux-${LINUX_VMAJOR}.${LINUX_VMINOR}.y"
LINUX_VERSION = "${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https;branch=${LINUX_STABLE_BRANCH}"
S = "${WORKDIR}/git"

python __anonymous() {
    kver = (int(d.getVar("LINUX_VMAJOR")), int(d.getVar("LINUX_VMINOR")))

    # Handle checksums of older COPYING files
    if kver <= (4, 17):
        d.setVar("LIC_FILES_CHKSUM", "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7")
    elif kver <= (5, 5):
        d.setVar("LIC_FILES_CHKSUM", "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814")
}
