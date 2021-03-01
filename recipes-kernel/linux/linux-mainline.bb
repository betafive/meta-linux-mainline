require linux-mainline-common.inc
SUMMARY += "(mainline)"

LINUX_VERSION = "5.12-rc1"
PV = "${LINUX_VERSION}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;protocol=https"
SRCREV = "fe07bfda2fb9cdef8a4d4008a409bb02f35f1bd8"
S = "${WORKDIR}/git"
