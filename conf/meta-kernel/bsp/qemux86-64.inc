KBUILD_DEFCONFIG = "x86_64_defconfig"
KCONFIG_MODE = "alldefconfig"
QB_ROOTFS_OPT = "-drive if=none,id=hd,file=@ROOTFS@,format=raw -device ahci,id=ahci -device ide-drive,drive=hd,bus=ahci.0"
QB_KERNEL_ROOT = "/dev/sda"
