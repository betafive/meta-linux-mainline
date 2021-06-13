SUMMARY = "cmdline.txt file used to boot the kernel on a Raspberry Pi device"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# This is a fallback recipe - in recent branches the rpi-cmdline recipe is
# provided by meta-raspberrypi. However, on dunfell we need to provide this
# recipe ourselves. By setting PV=0.1, this recipe should only be used if there
# is no rpi-cmdline recipe in meta-raspberrypi.

COMPATIBLE_MACHINE = "^rpi$"
PACKAGE_ARCH = "${MACHINE_ARCH}"
INHIBIT_DEFAULT_DEPS = "1"
inherit deploy nopackages

do_compile() {
    echo "dwc_otg.lpm_enable=0 root=/dev/mmcblk1p2 rw rootwait elevator=noop cma=256M@512M" > "${WORKDIR}/cmdline.txt"
}

do_deploy() {
    install -d "${DEPLOYDIR}/bcm2835-bootfiles"
    install -m 0644 "${WORKDIR}/cmdline.txt" "${DEPLOYDIR}/bcm2835-bootfiles/"
}

addtask deploy before do_build after do_install
do_deploy[dirs] += "${DEPLOYDIR}/bcm2835-bootfiles"
