#! /bin/bash

set -e

S=$1

( kas shell kas/${S}.yml -c 'bitbake --setscene-only core-image-base' || true ) | sed -e '/^NOTE: .*Started$/d' -e '/^NOTE: Running /d'
kas shell kas/${S}.yml -c 'bitbake --skip-setscene core-image-base' | sed -e '/^NOTE: .*Started$/d' -e '/^NOTE: Running /d'

mv build/tmp/deploy/images .
rm -rf build
