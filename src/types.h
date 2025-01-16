#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef void (*TaskFunction)(void);

typedef struct {
    uint32_t id;
    TaskFunction task;
    uint32_t priority;
} ActiveObject;

#endif // TYPES_H