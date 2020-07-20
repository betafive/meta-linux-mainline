DESCRIPTION = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

inherit kernel

# The ORC unwinder is enabled in x86_64_defconfig and needs libelf-dev
DEPENDS_append_x86-64 = " elfutils-native"

LINUX_VERSION = "${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}"
LINUX_BRANCH = "linux-${LINUX_VMAJOR}.${LINUX_VMINOR}.y"
PV = "${LINUX_VERSION}"

LINUX_GIT_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;branch=${LINUX_BRANCH};protocol=https"
LINUX_TARBALL_URI = "https://cdn.kernel.org/pub/linux/kernel/v${LINUX_VMAJOR}.x/linux-${LINUX_VERSION}.tar.xz"

# The download method may either be 'git' or 'tarball'.
LINUX_STABLE_DOWNLOAD ??= "git"
require linux-stable-${LINUX_STABLE_DOWNLOAD}.inc

python __anonymous() {
    # Handle checksums of older COPYING files
    vmajor = int(d.getVar("LINUX_VMAJOR"))
    vminor = int(d.getVar("LINUX_VMINOR"))
    if (vmajor, vminor) <= (4, 17):
        d.setVar("LIC_FILES_CHKSUM", "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7")
    elif (vmajor, vminor) <= (5, 5):
        d.setVar("LIC_FILES_CHKSUM", "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814")
}

do_configure_prepend() {
	if [ -n "${KBUILD_DEFCONFIG}" ] && [ -f "${S}/arch/${ARCH}/configs/${KBUILD_DEFCONFIG}" ]; then
		oe_runmake_call -C ${S} CC="${KERNEL_CC}" LD="${KERNEL_LD}" O=${B} ${KBUILD_DEFCONFIG}
	fi
}
