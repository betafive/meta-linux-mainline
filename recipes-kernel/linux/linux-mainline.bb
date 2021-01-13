require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.11-rc3"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "7c53f6b671f4aba70ff15e1b05148b10d58c2837"
S = "${WORKDIR}/git"
