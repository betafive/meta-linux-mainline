require linux-mainline-common.inc
SUMMARY += "(mainline)"

PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
S = "${WORKDIR}/git"
