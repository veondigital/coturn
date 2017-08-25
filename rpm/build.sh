#!/bin/bash

CPWD=`pwd`

. ./build.settings.sh

# YAJL

cd ${BUILDDIR}/SRPMS
wget http://vault.centos.org/centos/7/os/Source/SPackages/yajl-2.0.4-4.el7.src.rpm
rpm -i yajl-2.0.4-4.el7.src.rpm
rpmbuild -ba ${BUILDDIR}/SPECS/yajl.spec
ER=$?
if ! [ ${ER} -eq 0 ] ; then
    cd ${CPWD}
    exit -1
fi

# TURN

cd ${BUILDDIR}/tmp
rm -rf turnserver-${TURNVERSION}
git clone ${TURNSERVER_GIT_URL} --branch feature_BUTTON-5439 turnserver-${TURNVERSION}
ER=$?
if ! [ ${ER} -eq 0 ] ; then
    cd ${CPWD}
    exit -1
fi

cd turnserver-${TURNVERSION}
git submodule init
git submodule update
rm -fR .git
cd ..

tar zcf ${BUILDDIR}/SOURCES/turnserver-${TURNVERSION}.tar.gz turnserver-${TURNVERSION}
ER=$?
if ! [ ${ER} -eq 0 ] ; then
    cd ${CPWD}
    exit -1
fi

rpmbuild -ta ${BUILDDIR}/SOURCES/turnserver-${TURNVERSION}.tar.gz
ER=$?
if ! [ ${ER} -eq 0 ] ; then
    cd ${CPWD}
    exit -1
fi

# Make binary tarball

cd ${BUILDDIR}/RPMS/${ARCH}
mkdir -p di
mv *debuginfo* di
mv *devel* di
rm -rf turnserver-${TURNVERSION}
mkdir turnserver-${TURNVERSION}
mv *.rpm turnserver-${TURNVERSION}/

PLATFORM=`cat ${BUILDDIR}/platform`

tar cvfz turnserver-${TURNVERSION}.${PLATFORM}.${ARCH}.tar.gz turnserver-${TURNVERSION}

cd ${CPWD}
