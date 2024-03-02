# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

require linux-mainline-common.inc
SUMMARY += "(stable)"

LINUX_VERSION = "${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}"
PV = "${LINUX_VERSION}"

SRC_URI = " \
    https://cdn.kernel.org/pub/linux/kernel/v${LINUX_VMAJOR}.x/linux-${LINUX_VMAJOR}.${LINUX_VMINOR}.tar.xz;name=tarball \
    https://cdn.kernel.org/pub/linux/kernel/v${LINUX_VMAJOR}.x/patch-${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}.xz;downloadfilename=linux-${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}.patch.xz;name=patch \
    "
SRC_URI[tarball.sha256sum] = "${LINUX_SHA256_TARBALL}"
SRC_URI[patch.sha256sum] = "${LINUX_SHA256_PATCH}"
S = "${WORKDIR}/linux-${LINUX_VMAJOR}.${LINUX_VMINOR}"

python __anonymous() {
    kver = (int(d.getVar("LINUX_VMAJOR")), int(d.getVar("LINUX_VMINOR")))

    # Handle checksums of older COPYING files
    if kver <= (4, 17):
        d.setVar("LIC_FILES_CHKSUM", "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7")
    elif kver <= (5, 5):
        d.setVar("LIC_FILES_CHKSUM", "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814")
}
