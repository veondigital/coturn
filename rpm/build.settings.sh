#!/bin/bash

# Common settings script.

TURNVERSION=4.5.0.6
BUILDDIR=~/rpmbuild
ARCH=`uname -p`
TURNSERVER_GIT_URL=https://github.com/SteppeChange/coturn

WGETOPTIONS="--no-check-certificate"
RPMOPTIONS="-ivh --force"


