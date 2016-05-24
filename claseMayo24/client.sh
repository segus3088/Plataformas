#!/bin/bash
sudo apt-get update

sudo apt-get install -y nfs-common

sudo mkdir /shared

sudo mount $1:/shared /shared

df -h 

sudo apt-get install -y openmpi-bin openmpi-doc libopenmpi-dev