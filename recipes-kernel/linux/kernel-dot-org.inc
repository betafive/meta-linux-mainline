DESCRIPTION = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

inherit kernel

# The ORC unwinder is enabled in x86_64_defconfig and needs libelf-dev
DEPENDS_append_x86-64 = " elfutils-native"

LINUX_VERSION = "${LINUX_VMAJOR}.${LINUX_VMINOR}.${LINUX_VPATCH}"
LINUX_BRANCH = "linux-${LINUX_VMAJOR}.${LINUX_VMINOR}.y"
PV = "${LINUX_VERSION}"

LINUX_GIT_URI = "https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;branch=${LINUX_BRANCH}"
LINUX_TARBALL_URI = "https://cdn.kernel.org/pub/linux/kernel/v${LINUX_VMAJOR}.x/linux-${LINUX_VERSION}.tar.xz"

# The download method may either be 'git' or 'tarball'.
KERNEL_DOT_ORG_DOWNLOAD ??= "git"
require kernel-dot-org-${KERNEL_DOT_ORG_DOWNLOAD}.inc

python __anonymous() {
    if d.getVar("PREFERRED_PROVIDER_virtual/kernel") != "linux-stable":
        msg = "Skipping linux recipe (from meta-kernel) as it is not the preferred provider of virtual/kernel."
        raise bb.parse.SkipRecipe(msg)
}
