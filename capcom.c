#define pr_fmt(fmt) "capcom: " fmt
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/miscdevice.h>

static long capcom_ioctl(struct file* file, unsigned int request, unsigned long arg) {
	void (*user_function)(void) = (void*) arg;
	if (request == 0xAA012044) {
		user_function();
		return 0;
	}
	return -EINVAL;
}

static struct file_operations capcom_fops = {
	.unlocked_ioctl = capcom_ioctl,
};

static struct miscdevice capcom_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "capcom",
	.mode = 0666,
	.fops = &capcom_fops,
};

static int capcom_init(void) {
	misc_register(&capcom_misc);
	return 0;
}

static void capcom_exit(void) {
	misc_deregister(&capcom_misc);
}

module_init(capcom_init);
module_exit(capcom_exit);
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Matt Mullins <mmullins@mmlx.us>");
