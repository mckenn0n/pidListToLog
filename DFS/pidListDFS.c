#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/init_task.h>

void DFS(struct task_struct *task){   
    struct task_struct *child;
    struct list_head *list;

    printk("Name: %s, pid: [%d], state: %li\n", task->comm, task->pid, task->state);
    list_for_each(list, &task->children) {
        child = list_entry(list, struct task_struct, sibling);
        DFS(child);
    }
}


int DFS_init(void){
    printk(KERN_INFO "Removing Module\n");
    DFS(&init_task);

    return 0;
}


void DFS_exit(void){
    printk(KERN_INFO "Removing Task Lister Module...\n");
}

module_init(DFS_init);
module_exit(DFS_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("PID List DFS Tree Search");
MODULE_AUTHOR("SGG");