# Copyright (C) 2021, meta-linux-mainline contributors (auto-generated file)
# SPDX-License-Identifier: CC0-1.0
LINUX_VERSION = "6.4-rc7"
SRCREV = "45a3e24f65e90a047bef86f927ebdc4c710edaa1"
require linux-mainline.inc

SRC_URI += "file://20230117_arnd_workqueue_fix_enum_type_for_gcc_13.patch"
