/**
 * simple.c
 *
 * A simple kernel module.
 *
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>


/* This function is called when the module is loaded. */
int simple_init(void)
{
	// now_tick holds the value of jiffies defined in <linux/jiffies.h>
	unsigned long now_tick = jiffies;
	// now_tick_freq holds the value of HZ defined in <asm/param.h>
	int now_tick_freq = HZ;
	// print message for loading kernel module
	printk(KERN_INFO "Loading Kernel Module\n");
	// print golden ratio prime defined in hash.h
	printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);
	// print the value of jiffies
	printk(KERN_INFO "Value of jiffies is %lu\n", now_tick);
	// print the value of HZ
	printk(KERN_INFO "Value of HZ is %d\n", now_tick_freq);
	return 0;
}

/* This function is called when the module is removed.*/
void simple_exit(void)
{
	// a holds the unsigned long value 3300
	unsigned long int a = 3300;
	// b holds the unsigned value of 24
	unsigned int b = 24;
	// now_tick hold the value of jiffies
	unsigned long now_tick = jiffies;
	// print the gcd of 3300 and 24 using the gdc function defined in <linux/gcd.h>
	printk(KERN_INFO "The CGD of %lu and %u is %lu\n", a, b, gcd(a,b));
	// print the value of jiffies
	printk(KERN_INFO "Value of jiffies is %lu\n", now_tick);
	// print message for removing kernel module
	printk(KERN_INFO "Removing Kernel Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

