#!/bin/bash

if [ ! -d etcd-api ]; then
    echo "can't find etcd-api directory, checkout submodule first!"
    exit 1
fi

if [ ! -d yajl ]; then
    echo "can't find yajl directory, checkout submodule first!"
    exit 1
fi

cd yajl
./configure
make && sudo make install
cd ..

./configure
make
