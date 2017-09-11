#!/bin/bash

# Amazon Linux preparation script.

CPWD=`pwd`

. ./common.pre.build.sh

cd ${CPWD}

# Common packs

PACKS="yajl curl curl-devel libevent-devel mysql-devel sqlite sqlite-devel"
sudo yum -y install ${PACKS}
ER=$?
if ! [ ${ER} -eq 0 ] ; then
    echo "Cannot install package(s) ${PACKS}"
    cd ${CPWD}
    exit -1
fi

# Platform file

echo "amzn1" > ${BUILDDIR}/platform

cd ${CPWD}
