require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.13-rc5"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "614124bea77e452aa6df7a8714e8bc820b489922"
S = "${WORKDIR}/git"
