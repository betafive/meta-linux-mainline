require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.11-rc1"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "5c8fe583cce542aa0b84adc939ce85293de36e5e"
S = "${WORKDIR}/git"
