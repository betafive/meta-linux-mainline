DESCRIPTION = "Linux kernel (mainline)"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

inherit kernel

# The ORC unwinder is enabled in x86_64_defconfig and needs libelf-dev
DEPENDS_append_x86-64 = " elfutils-native"

LINUX_VERSION = "5.8-rc6"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "ba47d845d715a010f7b51f6f89bae32845e6acb7"
S = "${WORKDIR}/git"

python __anonymous() {
    if d.getVar("PREFERRED_PROVIDER_virtual/kernel") != "linux-mainline":
        msg = "Skipping linux recipe (from meta-kernel) as it is not the preferred provider of virtual/kernel."
        raise bb.parse.SkipRecipe(msg)
}
