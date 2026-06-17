#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "minigpu"

static int device_open(
        struct inode *inode,
        struct file *file)
{
    printk("MiniGPU opened\n");
    return 0;
}

static int device_release(
        struct inode *inode,
        struct file *file)
{
    return 0;
}

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release
};

static int __init minigpu_init(void)
{
    register_chrdev(240,
                    DEVICE_NAME,
                    &fops);

    printk("MiniGPU driver loaded\n");

    return 0;
}

static void __exit minigpu_exit(void)
{
    unregister_chrdev(240,
                      DEVICE_NAME);

    printk("MiniGPU unloaded\n");
}

module_init(minigpu_init);
module_exit(minigpu_exit);

MODULE_LICENSE("GPL");