meta-kernel
===========

A collection of Yocto Project recipes for the Linux kernel and related tools.

## Contents of this layer

This layer currently contains the following kernel recipes:

* `linux-stable` (multiple versions): These recipes follow the patch releases
  in each currently supported stable release series of the Linux kernel. The
  currently supported release series can be seen at
  [kernel.org](https://www.kernel.org/).

* `linux-mainline`: This recipe uses AUTOREV to pull the latest commit to the
  master branch of the mainline Linux repository. As this branch includes
  release candidate (rc) kernels it is only recommended for testing and active
  development.

It is expected that additional kernel recipes and other kernel related tools
will be added in the future.

## Using this layer

### As a dependency of a BSP layer

It is expected that some BSP layers will directly use this layer to provide a
vanilla kernel recipe where a vendor kernel is not needed. In these cases no
changes will be needed to make use of the kernel recipes in this layer.

### Replacing your vendor kernel

Many Board Support Package (BSP) layers default to using a vendor-specific
kernel repository (containing many patches which haven't been incorporated
into the upstream kernel) or an obsolete kernel version. However, most boards
are supported by the mainline Linux kernel to some degree or other. Switching
to a mainline kernel allows you to take advantage of bugfixes & new features
and enables you to work more closely with the kernel community.

The kernel recipes in this layer are intended as optional replacements for
the vendor kernel recipes included in a BSP directory. Simply including this
layer in your build will not alter the kernel recipe in use. To select a
kernel recipe from this layer you should override the
`PREFERRED_PROVIDER_virtual/kernel` variable to either `linux-stable` or
`linux-mainline` as appropriate. If using `linux-stable` it also also
possible to set `PREFERRED_VERSION_linux-stable` to choose a stable kernel
release series.

This layer is tested with the most recent Yocto Project release branch
(currently "dunfell") but should also work with the master branch without
changes.

## Contributing to this layer

To report bugs or request new recipes & features please use our [issue
tracker](https://gitlab.com/openembedded/community/meta-kernel/-/issues).

To submit changes to this layer please fork the repository on GitLab and
open a [merge request](https://gitlab.com/openembedded/community/meta-kernel/-/merge_requests).

## Maintainers

Paul Barker \<pbarker@konsulko.com\>
