# characterdevice
Operazione da useguire:
comandi terminali nella directory dei file sorgenti
make
sudo insmod hello.ko
sudo mknod /dev/hello c 241 0
sudo chmod 666 /dev/hello
echo -n abcdef >/dev/hello
cat /dev/hello
