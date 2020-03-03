# characterdevice
Operazione da useguire: <br/>
comandi terminali nella directory dei file sorgenti <br/>
make  <br/>
sudo insmod hello.ko  <br/>
sudo mknod /dev/hello c 241 0  <br/>
sudo chmod 666 /dev/hello  <br/>
echo -n "abcdef" >/dev/hello <br/>
cat /dev/hello <br/>

output previsto: l'ultimo carattere della stringa in questo caso f
