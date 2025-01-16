#ifndef ACTIVE_OBJECT_H
#define ACTIVE_OBJECT_H

#include <stdint.h>
#include <stdbool.h>

// Task structure
typedef struct {
    void (*function)(void* args);
    void* args;
} Task;

// Queue size
#define QUEUE_SIZE 10

// Functions
bool enqueue_task(void (*function)(void*), void* args);
void scheduler_run(void);

#endif // ACTIVE_OBJECT_H
