# ChangeLog for meta-linux-mainline

<!--
Copyright (C) 2021, meta-linux-mainline contributors
SPDX-License-Identifier: CC-BY-4.0
-->

This ChangeLog documents high level changes which may affect users of this
layer. Entries are grouped by the approximate date at which the changes were
merged to the master branch.

Regular updates to the linux-stable and linux-mainline recipes are not included
in this document as that would lead to far too much noise. However, changes to
the default LTS release series will be documented here.

Changes only visible to developers of this layer (e.g. changes to layer update
and autobuild scripts) will not be documented in this file.

For a detailed list of all changes consult the git log.

## 2025-05

* Dropped support for Yocto Project 5.1 "styhead" branch.

* Added support for Yocto Project 5.2 "walnascar" branch.

## 2025-03

* Added support for overriding `SRC_URI` in our kernel recipes via the new
  `LINUX_STABLE_GIT_URI` and `LINUX_MAINLINE_GIT_URI` variables. Setting these
  variables when local git mirrors are available ensures that there will be no
  unnecessary load on kernel.org infrastructure.

## 2025-01

* Dropped now obsolete 4.19 kernel series and set `OLDEST_KERNEL` to 5.4.

## 2024-12

* Switch default LTS kernel series to 6.12.

## 2024-11

* Dropped support for nios2 and arc architectures in our kernel recipes as
  they're neither used or tested.

* Added sensible defaults for `KCONFIG_MODE` and `KBUILD_DEFCONFIG` in our
  kernel recipes.

* Added new `LINUX_MINIMUM_VMAJOR` and `LINUX_MINIMUM_VMINOR` variables so that
  machine configurations can easily specify the minimum kernel version they
  support when using our kernel recipes.

* Added new `KERNEL_EXTRA_SRC_URI` variable which can be used to easily extend
  the `SRC_URI` used by our kernel recipes.

* Modified kernel config for qemuriscv32 to fix the build.

## 2024-10

* Switched back to using kernel-yocto bbclass in our kernel recipes so people
  can use config fragments, defconfigs in `SRC_URI` and other nice kernel-yocto
  features.

* Added some basic contribution guidelines.

## 2024-09

* Dropped support for Yocto Project 4.3 "nanbield" branch.

* Added support for Yocto Project 5.1 "styhead" branch.

* Added `truncate` to `HOSTTOOLS` as recent mainline & stable kernels use this
  as part of the build process.

## 2024-08

* Disabled buildpath QA check as several generated source files in the kernel
  include the full path to the build directory.

## 2024-07

* Disabled patch-status QA check as we use patch files directly from kernel.org
  which do not include the Upstream-Status line required by Yocto Project.

## 2024-05

* Dropped support for Yocto Project 3.1 "dunfell" LTS branch.

* Added support for Yocto Project 5.0 "scarthgap" LTS branch.

## 2024-03

* Dropped obsolete 4.14 kernel series.

* Use `KBUILD_DEFCONFIG` as a make target instead of looking for a defconfig
  file to copy. This is required so that we can build for 32-bit RISC-V targets
  with the latest kernel releases. This requires dropping the kernel-yocto
  bbclass from our kernel recipes.

* Set `OLDEST_KERNEL` for automated builds to ensure that glibc is configured to
  support all kernel versions in this layer. Users of this layer will need to
  set `OLDEST_KERNEL` in their local or distro configuration files if they are
  using a kernel series older than 5.15.

## 2024-01

* Refactored autobuild script, with improved logging and fixed support for
  site.conf files.

## 2023-12

* Updated kas configuration format to v14, using the new `branch` property
  instead of the obsolete `refspec` property.

* Updated SPDX license name in the kernel recipes, it is now `GPL-2.0-only` as
  `GPLv2` is obsolete.

* Drop support for Yocto Project 4.2 "Mickledore" release series.

## 2023-11

* Add support for Yocto Project 4.3 "Nanbield" release series.

* Add kas configs for building v6.1.x and v6.6.x series kernels.

* Switch LTS branch to v6.6.x series.

* Update repository URL to <https://github.com/betafive/meta-linux-mainline>.

## 2023-06

* Overhaul autobuild infrastructure - we're now using kas to handle each build
  to make it easier to run single builds and to debug build failures.

* Dropped raspberrypi4 builds from the autobuild matrix.

* Drop compatibility with obsolete non-LTS Yocto Project branches (gatesgarth,
  hardknott, honister & langdale). These are no longer part of our test matrix
  anyway so advertising compatibility isn't wise.

* Tidy up documentation and point at the project's current GitHub repository in
  the contribution instructions.

## 2023-03

* Drop Linux 4.9 LTS series as it has reached EOL.

* Switch LTS branch to Linux 6.1.

* Mark this layer as compatible with the Yocto Project mickledore branch.

## 2022-12

* Mark this layer as compatible with the Yocto Project langdale branch.

* Add configs for qemu RISC-V machines.

* Use GitHub Actions to automatically update the Yocto Project release tracking
  branches (i.e. dunfell, kirkstone, etc) when changes are pushed to the main
  branch.

## 2022-02

* Drop Linux 4.4 LTS series as it has reached EOL.

* Mark this layer as compatible with the Yocto Project kirkstone LTS branch.

* Moved the project to GitHub. Sourcehut was nice, but it's easier for new folks
  to contribute to the project via GitHub.

## 2022-01

* Dropped support for old overrides syntax.

* Carry a recipe for python3-dtschema-wrapper so we can build Linux 5.16 or
  later on the Yocto Project dunfell branch.

* Switch LTS branch to Linux 5.15.

## 2021-08-05

* Convert to the new override syntax required by the master branch of bitbake,
  openembedded-core & poky. Compatibility with all releases since dunfell should
  be maintained as support for the new syntax has been backported to the
  relevant bitbake branches. However, if the old syntax is needed for any reason
  it can still be activated by adding the following assignment to your local or
  distro conf file:

      LINUX_MAINLINE_OVERRIDE_SYNTAX = "old"

  Support for the old syntax will be retained for a few months before final
  removal.

* Simplified the raspberrypi4 config and kernel inc files to not use unnecessary
  overrides.

* Drop support for gatesgarth branch.

* Extended the update-layer script to automatically commit changes.

## 2021-06-18

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

## dunfell-r1 (2020-05-26)

Initial release for the Yocto Project `dunfell` branch.

* Recipes for LTS, stable & mainline kernels from <https://kernel.org>.

* BSP include files for `qemux86-64` and `raspberrypi3`.

* Example build configurations using the `kas` build tool.

* Automated build testing using GitLab CI.
