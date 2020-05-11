SUMMARY = "cmdline.txt file used to boot the kernel on a Raspberry Pi device"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

COMPATIBLE_MACHINE = "^rpi$"
INHIBIT_DEFAULT_DEPS = "1"
inherit deploy nopackages

do_compile() {
    echo "root=/dev/mmcblk0p2 rw rootwait elevator=noop cma=256M@512M" > "${WORKDIR}/cmdline.txt"
}

do_deploy() {
    install -d "${DEPLOYDIR}/bcm2835-bootfiles"
    install -m 0644 "${WORKDIR}/cmdline.txt" "${DEPLOYDIR}/bcm2835-bootfiles/"
}

addtask deploy before do_build after do_install
do_deploy[dirs] += "${DEPLOYDIR}/bcm2835-bootfiles"
