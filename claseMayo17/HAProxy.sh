#!/bin/bash
sudo apt-get update
Sudo DEBIAN_FRONTEND=noninteractive apt-get install -y haproxy
sudo sed -i 's/ENABLED=0/ENABLED=1/g' /etc/default/haproxy
sudo mv /etc/haproxy/haproxy.cfg /etc/haproxy/haproxy.cfg.bckp
sudo cp -f /vagrant/haproxy.cfg /etc/haproxy/
sudo service haproxy start
