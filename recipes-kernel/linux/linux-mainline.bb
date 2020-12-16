require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.10"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "2c85ebc57b3e1817b6ce1a6b703928e113a90442"
S = "${WORKDIR}/git"
