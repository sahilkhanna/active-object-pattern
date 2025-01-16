#include "active_object.h"
#include <stdio.h>

// Example task function
void print_message_task(void* args) {
    const char* message = (const char*)args;
    printf("Task executed: %s\n", message);
}

int main(void) {
    enqueue_task(print_message_task, "Hello, Active Object!");
    enqueue_task(print_message_task, "Another task");

    scheduler_run();

    return 0;
}
