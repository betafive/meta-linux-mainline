require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.11"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "f40ddce88593482919761f74910f42f4b84c004b"
S = "${WORKDIR}/git"
