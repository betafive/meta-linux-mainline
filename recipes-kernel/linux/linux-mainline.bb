require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.10-rc3"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "f8394f232b1eab649ce2df5c5f15b0e528c92091"
S = "${WORKDIR}/git"
