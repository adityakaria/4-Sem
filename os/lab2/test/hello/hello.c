#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AJK");
MODULE_DESCRIPTION("Kernel Hello World Module");
MODULE_VERSION("1.0.0");

static int __init exampleStart(void){
	printk(KERN_INFO "Hello World\n");
	return 0;
}

static void __exit exampleEnd(void){
	printk(KERN_INFO "Ending module\n");
}

module_init(exampleStart);
module_exit(exampleEnd);
