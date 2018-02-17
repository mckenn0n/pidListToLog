#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/init_task.h>

int pid_init(void){
	struct task_struct *task;

	printk(KERN_INFO "Loading Module\n");

	for_each_process(task){
	   printk("Name: %s PID: [%d], state: %li\n", task->comm, task->pid, task->state);
	}
	return 0;
}

void pid_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

module_init( pid_init );
module_exit( pid_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("PID List");
MODULE_AUTHOR("SGG");