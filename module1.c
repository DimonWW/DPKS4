
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static unsigned int repeats = 1;
module_param(repeats, uint, S_IRUGO);
MODULE_PARM_DESC(repeats, "How many hello to print");

static int __init module1_init(void)
{
	unsigned int repeat;
	if (repeats > 10)
	{
		printk(KERN_ERR "Cannot repeat more than 10 times\n");
		return -EINVAL;
	}
	if (repeats >= 5 && repeats <= 10)
	{
		printk(KERN_WARNING "Repeatition from 5 to 10 times\n");
	}
	if (repeats == 0)
	{
		printk(KERN_WARNING "No repeatition\n");
	}
	for (repeat = 0; repeat < repeats; repeat++)
	{
		printk(KERN_INFO "Hello, world!\n");
	}
	return 0;
}
static void __exit module1_exit(void)
{
	printk(KERN_EMERG "Module 1 exit\n");
}

module_init(module1_init);
module_exit(module1_exit);

MODULE_AUTHOR("Dmitry Korenko");
MODULE_DESCRIPTION("Training to build linux module");
MODULE_LICENSE("Dual BSD/GPL");
