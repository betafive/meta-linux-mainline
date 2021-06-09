# meta-linux-mainline layer build tests
#
# Copyright (C) 2020, meta-linux-mainline contributors
# SPDX-License-Identifier: MIT

import datetime
import os
import subprocess


def do_build(machine, kernel):
    stamp = datetime.datetime.now().isoformat()
    if "SITE_CONF_FILE" in os.environ:
        os.makedirs("build/conf", exist_ok=True)
        if os.path.exists("build/conf/site.conf"):
            os.unlink("build/conf/site.conf")
        os.symlink(
            os.path.realpath(os.environ["SITE_CONF_FILE"]), "build/conf/site.conf"
        )

    os.makedirs("test_logs", exist_ok=True)
    fout = open(f"test_logs/{machine}_{kernel}_{stamp}.log", "w")
    r = subprocess.run(
        f"kas build --update --force-checkout kas/{machine}_{kernel}.yml",
        shell=True,
        check=True,
        stdout=fout,
        stderr=fout,
    )

    return r.returncode == 0


def test_raspberrypi3_mainline():
    assert do_build("raspberrypi3", "mainline")


def test_raspberrypi3_stable():
    assert do_build("raspberrypi3", "stable")


def test_raspberrypi3_lts():
    assert do_build("raspberrypi3", "lts")


def test_qemux86_64_mainline():
    assert do_build("qemux86-64", "mainline")


def test_qemux86_64_stable():
    assert do_build("qemux86-64", "stable")


def test_qemux86_64_lts():
    assert do_build("qemux86-64", "lts")
