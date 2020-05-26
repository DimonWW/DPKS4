#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "module2.h"

void print_text(unsigned int repeats)
{
	unsigned int repeat;
	for (repeat = 0; repeat < repeats; repeat++)
	{
		pr_info("Hello, world!\n");
	}
}
EXPORT_SYMBOL(print_text);
static int __init module2_init(void)
{
	pr_info("Exporting the function...");
	return 0;
}
static void __exit module2_exit(void)
{
	pr_info("Module 2 exit. No more exporting the function.\n");
}

module_init(module2_init);
module_exit(module2_exit);
MODULE_AUTHOR("Dmitry Korenko");
MODULE_DESCRIPTION("Training to export a funcion");
MODULE_LICENSE("Dual BSD/GPL");
