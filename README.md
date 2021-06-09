meta-linux-mainline
===================

A collection of Yocto Project recipes for the mainline and stable Linux
kernel releases from kernel.org.

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

## Using this layer

### As a dependency of a BSP layer

It is expected that some BSP layers will directly use this layer to provide a
vanilla kernel recipe where a vendor kernel is not needed. In these cases no
changes will be needed to make use of the kernel recipes in this layer.

For other BSP layers you may be given a choice between a vendor kernel and a
vanilla kernel. The method of choosing the desired kernel provider will be
BSP-specific. An example of this can be seen in the
[meta-sancloud](https://github.com/sancloudltd/meta-sancloud/) BSP where the
kernel recipes from this layer are used if `BBE_KERNEL_PROVIDER` is set to
`stable`, `lts` or `mainline`.

### Replacing your vendor kernel

Many Board Support Package (BSP) layers default to using a vendor-specific
kernel repository (containing many patches which haven't been incorporated
into the upstream kernel) or an obsolete kernel version. However, most boards
are supported by the mainline Linux kernel to some degree or other. Switching
to a mainline kernel allows you to take advantage of bugfixes & new features
and enables you to work more closely with the kernel community.

#### Selecting a kernel recipe

The kernel recipes in this layer are intended as optional replacements for
the vendor kernel recipes included in a BSP directory. Simply including this
layer in your build will not alter the kernel recipe in use. To select a
kernel recipe from this layer you should override the
`PREFERRED_PROVIDER_virtual/kernel` variable to either `linux-stable` or
`linux-mainline` as appropriate. If using `linux-stable` it also also
possible to set `PREFERRED_VERSION_linux-stable` to choose a stable kernel
release series.

To simplify the process of selecting a kernel recipe from this layer, 3
`.inc` files are provided which can be included from your `local.conf` file
or from a distro conf file:

* `conf/linux-mainline/stable.inc`: Selects the `linux-stable` recipe for the
  latest stable kernel version (typically not an LTS kernel).

* `conf/linux-mainline/lts.inc`: Selects the `linux-stable` recipe for the
  latest LTS kernel version.

* `conf/linux-mainline/mainline.inc`: Selects the `linux-mainline` recipe.

#### Board support

To support a particular target board with `linux-stable` or `linux-mainline`
it is usually necessary to select an appropriate defconfig from the kernel
source tree. It may also be necessary to provide additional configuration or
to make changes to the bootloader to properly support a vanilla kernel.

This layer includes a selection of `.inc` files which add support for a
vanilla kernel if it is not supported already by the relevant BSP layer. To
use the appropriate `.inc` file, add the following line to your `local.conf`
or distro conf file:

    include conf/linux-mainline/bsp/${MACHINE}

#### Using kas

The kas build configuration in this repository demonstrate how this can be
achieved for both qemux86-64 (from the openembeded-core layer) and
raspberrypi3 (from the
[meta-raspberrypi](https://github.com/agherzan/meta-raspberrypi) BSP layer.
These configurations are used with the [kas](https://github.com/siemens/kas)
tool.

### Additional configuration options

The `linux-stable` recipes allow the source download method to be chosen
using the `LINUX_STABLE_DOWNLOAD` variable. The supported values are:

* `git` (default): The `linux-stable` git repository is pulled from
  git.kernel.org. This method requires more bandwidth for the initial download
  but subsequent updates will be faster.

* `tarball`: The release tarball for the selected kernel recipe is downloaded.
  This method requires less bandwidth for the initial download but after
  several updates may result in higher overall bandwidth use. This method is
  best suited to throw-away build environments or one-off builds where future
  updates are not expected to use the same downloads directory.

## Contributing to this layer

meta-linux-mainline is developed on [sourcehut](https://sr.ht/) at
<https://sr.ht/~pbarker/meta-linux-mainline/>.

If you find any bugs or have a feature request feel free to open a ticket in
the [issue tracker](https://todo.sr.ht/~pbarker/meta-linux-mainline).

To submit patches to meta-linux-mainline please
[send them to my public inbox](mailto:~pbarker/public-inbox@lists.sr.ht?subject=[meta-linux-mainline])
with `[meta-linux-mainline]` in the subject line. Please use
[plain text email](https://useplaintext.email/) when sending messages to this
list. Submitted patches and other discussions may be found in the
[archives](https://lists.sr.ht/~pbarker/public-inbox) of this mailing list. The
following commands can be used to configure git to format patches appropriately:

```
git config format.to '~pbarker/public-inbox@lists.sr.ht'
git config format.subjectPrefix 'meta-linux-mainline][PATCH'
```

Further instructions on how to set up git to send emails can be found at
[git-send-email.io](https://git-send-email.io/).

## Maintainers

Paul Barker \<paul@pbarker.dev\>
