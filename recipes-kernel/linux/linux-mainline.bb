require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.10-rc7"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "0477e92881850d44910a7e94fc2c46f96faa131f"
S = "${WORKDIR}/git"
