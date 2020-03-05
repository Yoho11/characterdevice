# characterdevice
Operazione da useguire: <br/>
comandi terminali nella directory dei file sorgenti <br/>
make  <br/>
sudo insmod hello.ko  <br/>
sudo mknod /dev/hello c 241 0  <br/>
sudo chmod 666 /dev/hello  <br/>
echo "abcdef" >/dev/hello <br/>
cat /dev/hello <br/>

output previsto: abcdef
