#! /bin/bash

set -e

S=$1

kas build kas/test-${S}.yml
