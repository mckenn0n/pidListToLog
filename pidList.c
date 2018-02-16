#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>

struct task_struct *task;

for_each_process(task)
{
   printk("Name: %s PID: [%d]\n", task->comm, task->pid);
}