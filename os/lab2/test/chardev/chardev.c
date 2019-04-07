#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<asm/uaccess.h>

//functions
int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *,struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file*,char *, size_t,loff_t *);
static ssize_t device_write(struct file*,const char*, size_t,loff_t *);

//definitions
#define DEVICE_NAME "chardev"
#define BUF_LEN 80

//global variables
static int Major;
static int Device_Open = 0;
static char msg[BUF_LEN];
static char *msg_Ptr;
static struct file_operations fops ={
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

//actual definition begins here
int init_module(void){
	Major = register_chrdev(0,DEVICE_NAME,&fops);

	if(Major<0){
		printk(KERN_ALERT "Registering char device failed with %d\n",Major);
		return Major;
	}
	printk(KERN_INFO "Major number assigned is %d\n",Major);
	return 0;
}

void cleanup_module(void){
	unregister_chrdev(Major, DEVICE_NAME);
}

static int device_open(struct inode * a,struct file * b){
	static int counter=0;
	if(Device_Open)
		return -EBUSY;
	Device_Open++;
	sprintf(msg,"%d\n",counter++);
	msg_Ptr = msg;
	try_module_get(THIS_MODULE);
	return 0;
}

static int device_release(struct inode *a, struct file *b){
	Device_Open--;
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t device_read(struct file *filp,char *buffer,size_t length,loff_t * offset){
	int bytes_read = 0;
	if (*msg_Ptr == 0)
		return 0;
	while (length && *msg_Ptr){
		put_user(*(msg_Ptr++), buffer++);
		length--;
		bytes_read++;
	}
	return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t * off){
	printk(KERN_ALERT "Sorry, this operation isn't supported.\n");
	return -EINVAL;
}
