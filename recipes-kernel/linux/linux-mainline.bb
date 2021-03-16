require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.12-rc3"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "1e28eed17697bcf343c6743f0028cc3b5dd88bf0"
S = "${WORKDIR}/git"
