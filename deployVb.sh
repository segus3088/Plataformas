#!/bin/bash

#creado la variable del nombre
#leyendo la variable del nombre de la maquina
echo "Nombre de la maquina:"
read VM


#Create a 32GB “dynamic” disk.
VBoxManage createhd --filename $VM.vdi --size 32768

#Creando una copia mas apropiada para la maquina
VBoxManage createvm --name $VM --ostype "Linux_64" --register

#Creando controlado Add a SATA controller with the dynamic disk attached.
VBoxManage storagectl $VM --name "SATA Controller" --add sata --controller IntelAHCI

VBoxManage storageattach $VM --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium $VM.vdi

#Adicionanod controlador DVD Add an IDE controller with a DVD drive attached, and the install ISO inserted into the drive:
VBoxManage storagectl $VM --name "IDE Controller" --add ide

#se coloca el path to image of SO to install
#VBoxManage storageattach $VM --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium /path/to/SO.iso

#Configuraciones generales Misc system settings.
VBoxManage modifyvm $VM --ioapic on
VBoxManage modifyvm $VM --boot1 dvd --boot2 disk --boot3 none --boot4 none
VBoxManage modifyvm $VM --memory 1024 --vram 128
VBoxManage modifyvm $VM --nic1 bridged --bridgeadapter1 e1000g0

#Configuration is all done, boot it up! If you’ve done this one a remote machine, you can RDP to the console via vboxhost:3389.
#VBoxHeadless -s $VM

#Para apagar y sacar el DVD.Once you have configured the operating system, you can shutdown and eject the DVD.
#VBoxManage storageattach $VM --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium none


