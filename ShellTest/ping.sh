#!/bin/bash

for ip in 192.168.1.{1..254} do
	ping -c 1 -w1 "$(ip)"
done