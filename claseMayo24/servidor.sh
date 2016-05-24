#!/bin/bash
sudo apt-get update
sudo apt-get install -y nfs-kernel-server
sudo mkdir /shared
sudo chown nobody:nogroup /shared
sudo chmod 1777 /shared

sudo echo "/shared *(rw,sync,no_subtree_check)" >> /etc/exports

sudo exportfs -a
sudo service nfs-kernel-server start

sudo apt-get install -y openmpi-bin openmpi-doc libopenmpi-dev