# Copyright (C) 2020-2021, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

SUMMARY = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

inherit kernel
inherit kernel-yocto

require linux-mainline-overrides-${LINUX_MAINLINE_OVERRIDE_SYNTAX}.inc
