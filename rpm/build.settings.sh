#!/bin/bash

# Common settings script.

TURNVERSION=4.4.5.4
BUILDDIR=~/rpmbuild
ARCH=`uname -p`
TURNSERVER_GIT_URL=https://github.com/SteppeChange/coturn.git

WGETOPTIONS="--no-check-certificate"
RPMOPTIONS="-ivh --force"


