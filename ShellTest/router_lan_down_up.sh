#!/bin/bash -x
ifconfig br0     down
ifconfig eth0    down
ifconfig eth0.2  down
ifconfig eth0.3  down
ifconfig eth0.4  down
ifconfig nas0    down

sleep 3

ifconfig br0     up
ifconfig eth0    up
ifconfig eth0.2  up
ifconfig eth0.3  up
ifconfig eth0.4  up
ifconfig nas0    up
