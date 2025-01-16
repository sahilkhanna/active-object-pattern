#include "active_object.h"

static Task task_queue[QUEUE_SIZE];
static int queue_head = 0, queue_tail = 0;

bool enqueue_task(void (*function)(void*), void* args) {
    int next_head = (queue_head + 1) % QUEUE_SIZE;
    if (next_head == queue_tail) {
        return false;  // Queue full
    }
    task_queue[queue_head].function = function;
    task_queue[queue_head].args = args;
    queue_head = next_head;
    return true;
}

void scheduler_run(void) {
    while (queue_head != queue_tail) {
        Task task = task_queue[queue_tail];
        queue_tail = (queue_tail + 1) % QUEUE_SIZE;
        task.function(task.args);
    }
}
