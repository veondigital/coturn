#!/bin/bash

export ZONE=bee
export SECRET_KEY="34819d7beeabb9260a5c854bc85b3e44D"
export ETCD_ADDRESS="192.168.1.80:2379"
export EXTERNAL_IP=192.168.1.80
export MIN_PORT=30000
export MAX_PORT=50000
export OPTIMAL_THREADS=0
export DATADOG_AGENT_ADDRESS="127.0.0.1"
export DATADOG_PORT=8125
export CALLS_LIMIT=100

./bin/turnserver -c ./etc/turnserver.conf


