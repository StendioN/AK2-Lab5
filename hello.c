#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>

MODULE_AUTHOR("Ihor Lialin <i_lyalin@ukr.net>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint param = 1;
module_param(param,uint,0);
MODULE_PARM_DESC(param, "The amount of params to print Hello world");

static int __init initter(void)
{
  uint i = 0;

  printk(KERN_INFO "param: %d\n", param);

  if(param == 0) {
    printk(KERN_WARNING "The param is 0");
  }else if(param >=5 && param <= 10) {
    printk(KERN_WARNING "The param is between 5 and 10");
  } else if(param > 10) {
    printk(KERN_ERR "The param is greater than 10");
    return -EINVAL;
  }

  for(i = 0; i < param; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  return 0;
}

static void __exit exitter(void)
{
  /* Do nothing here right now */
}

module_init(initter);
module_exit(exitter);
