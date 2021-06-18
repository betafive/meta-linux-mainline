<!--
Copyright (C) 2021, meta-linux-mainline contributors
SPDX-License-Identifier: CC-BY-4.0
-->

ChangeLog for meta-linux-mainline
=================================

This ChangeLog documents high level changes which may affect users of this
layer. Entries are grouped by the approximate date at which the changes were
merged to the master branch.

Regular updates to the linux-stable and linux-mainline recipes are not included
in this document as that would lead to far too much noise. However, changes to
the default LTS release series will be documented here.

For a detailed list of all changes consult the git log.

2021-06-18
----------

* Project reboot, simplifying maintenance by only focusing on a single `master`
  branch. This branch aims to support all currently maintained Yocto Project
  releases (`dunfell` and `hardknott` today) as well as the upstream master
  branch.

* Project home is moved to sourehut:
  <https://sr.ht/~pbarker/meta-linux-mainline/>.

* Update default LTS kernel to 5.10 series.

* Update supported Raspberry Pi targets to `raspberrypi4` and `raspberrypi4-64`.

* Add out-of-the-box support for more QEMU targets. We now support `qemux86`,
  `qemux86-64`, `qemuarm` and `qemuarm64`.

* linux-stable recipes now download a tarball of the appropriate mainline
  release (e.g. v5.12) and a patch file to update to the appropriate stable
  release (e.g. v5.12.8). This keeps initial download size small but does not
  waste the bandwidth of downloading a large tarball for every minor update.

* New `scripts/autobuild` script to automate testing this layer. This replaces
  the kas build configurations and pytest test cases previously used.

dunfell-r1 (2020-05-26)
-----------------------

Initial release for the Yocto Project `dunfell` branch.

* Recipes for LTS, stable & mainline kernels from <https://kernel.org>.

* BSP include files for `qemux86-64` and `raspberrypi3`.

* Example build configurations using the `kas` build tool.

* Automated build testing using GitLab CI.
