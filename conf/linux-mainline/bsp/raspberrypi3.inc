RPI_KERNEL_DEVICETREE = " \
    bcm2837-rpi-3-b.dtb \
    bcm2837-rpi-3-b-plus.dtb \
    "
RPI_KERNEL_DEVICETREE_OVERLAYS = ""
RPI_EXTRA_CONFIG += " \
    upstream_kernel=1 \n \
    avoid_warnings=2 \n"

KBUILD_DEFCONFIG = "multi_v7_defconfig"
KCONFIG_MODE = "alldefconfig"
MACHINE_FEATURES_remove_rpi = "vc4graphics"

RPI_EXTRA_WIC_DEPENDS_rpi = "rpi-cmdline:do_deploy"
do_image_wic[depends] += "${RPI_EXTRA_WIC_DEPENDS}"

python __anonymous() {
    # Make sure that the selected kernel version supports the target machine
    if d.getVar("PN") == "linux-stable" and d.getVar("MACHINE") == "raspberrypi3":
        vmajor = int(d.getVar("LINUX_VMAJOR"))
        vminor = int(d.getVar("LINUX_VMINOR"))
        if (vmajor, vminor) < (4, 19):
            msg = "Skipping linux-stable recipe (from meta-linux-mainline) as it is too old to support raspberrypi3"
            raise bb.parse.SkipRecipe(msg)
}
