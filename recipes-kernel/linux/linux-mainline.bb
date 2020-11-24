require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.10-rc5"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "418baf2c28f3473039f2f7377760bd8f6897ae18"
S = "${WORKDIR}/git"
