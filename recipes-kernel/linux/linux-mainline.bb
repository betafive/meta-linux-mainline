require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.10-rc2"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "3cea11cd5e3b00d91caf0b4730194039b45c5891"
S = "${WORKDIR}/git"
