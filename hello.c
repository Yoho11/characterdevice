#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> 
#include <linux/slab.h> 
#include <linux/fs.h> 
#include <linux/errno.h> 
#include <linux/types.h> 
#include <linux/proc_fs.h>
#include <linux/fcntl.h> 
#include <linux/uaccess.h> 
MODULE_LICENSE("Dual BSD/GPL");
#define DEVICE_NAME "hello"
/* Dichiarazioni funzioni */
int h_open(struct inode *inode, struct file *filp);
int h_release(struct inode *inode, struct file *filp);
ssize_t h_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
ssize_t h_write(struct file *filp,const char *buf, size_t count, loff_t *f_pos);
void hello_exit(void);
int hello_init(void);
/* Struttura file operations*/
struct file_operations memory_fops = {  
	.read= h_read,  
	.write= h_write,  
	.open=h_open,  
	.release= h_release
};
/* Dichiarazione init e exit */
module_init(hello_init);
module_exit(hello_exit);
/* Major number */
int major = 241;
/* Buffer dati */
char *memory_buffer;
static short size_of_message;
int hello_init(void){
	int result;
	/* Registrazione device*/
	result=register_chrdev(major, DEVICE_NAME, &memory_fops);
	if(result<0){
		printk("<1>hello: impossibile ottenere il major number %d\n",major);
	return result;
	}
	/*Allocazione memoria*/
	memory_buffer=kmalloc(1,GFP_KERNEL);
	if(!memory_buffer){
		result=-ENOMEM;
		goto fail;
	}
	memset(memory_buffer,0,1);
	printk("<1>Inserimento modulo\n");
	return 0;
	fail:
		hello_exit();
		return result;
}

void hello_exit(void){
	/* Rilascio major number */
	unregister_chrdev(major,DEVICE_NAME);
	/* Rilascio memoria */
	if(memory_buffer){
		kfree(memory_buffer);
	}
	printk("<1>Rimozione modulo\n");
}

int h_open(struct inode *inode, struct file *flip){
	/* Successo */
	return 0;
}

int h_release(struct inode *inode, struct file *flip){
	/* Successo */
	return 0;
}

ssize_t h_read(struct file *flip, char *buf, size_t count, loff_t *f_pos){
	/* Trasferimento dati */
	copy_to_user(buf, memory_buffer,1);
	if(*f_pos==0){
		*f_pos+=1;
		return 1;
	}else{
		return 0;
	}
}

ssize_t h_write(struct file *flip,const char *buf, size_t count, loff_t *f_pos){
	char *tmp;
	tmp=buf+count-1;
	copy_from_user(memory_buffer, tmp, 1);
	return 1;
}

