#!/bin/bash

export ZONE=bee
export SECRET_KEY="34819d7beeabb9260a5c854bc85b3e44D"
export ETCD_ADDRESS="192.168.1.80:2379"
export EXTERNAL_IP=192.168.1.80
export MIN_PORT=30000
export MAX_PORT=50000
export OPTIMAL_THREADS=0

./bin/turnserver -c ./etc/turnserver.conf


