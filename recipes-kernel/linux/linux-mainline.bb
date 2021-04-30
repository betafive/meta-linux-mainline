require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.12"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "9f4ad9e425a1d3b6a34617b8ea226d56a119a717"
S = "${WORKDIR}/git"
