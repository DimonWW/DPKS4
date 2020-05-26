#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "module2.h"

static unsigned int repeats = 1;

module_param(repeats, uint, S_IRUGO);
MODULE_PARM_DESC(repeats, "How many hello to print");
static int __init module3_init(void)
{
	if (repeats > 10)
	{
		pr_err("Cannot repeat more than 10 times\n");
		return -EINVAL;
	}
	if (repeats >= 5 && repeats <= 10)
	{
		pr_warn("Repeatition from 5 to 10 times\n");
	}
	if (repeats == 0)
	{
		pr_warn("No repeatition\n");
	}
	print_text(repeats);
	return 0;
}
static void __exit module3_exit(void)
{
	pr_info("Module 3 exit\n");
}

module_init(module3_init);
module_exit(module3_exit);
MODULE_AUTHOR("Dmitry Korenko");
MODULE_DESCRIPTION("Training to import a function");
MODULE_LICENSE("Dual BSD/GPL");
