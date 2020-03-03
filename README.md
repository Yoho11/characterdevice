# characterdevice
Operazione da useguire:
comandi terminali nella directory dei file sorgenti
make \n
sudo insmod hello.ko \n
sudo mknod /dev/hello c 241 0 \n 
sudo chmod 666 /dev/hello \n
echo -n abcdef >/dev/hello \n
cat /dev/hello \n
