#include "unity/unity.h"
#include "active_object.h"
#include <string.h>

static char result_buffer[100];
static int result_index = 0;

void clear_result_buffer() {
    memset(result_buffer, 0, sizeof(result_buffer));
    result_index = 0;
}

void append_to_result_buffer(const char* message) {
    result_index += snprintf(&result_buffer[result_index], sizeof(result_buffer) - result_index, "%s ", message);
}

// Mock task function
void mock_task(void* args) {
    const char* message = (const char*)args;
    append_to_result_buffer(message);
}

void test_enqueue_and_execute_tasks() {
    clear_result_buffer();

    enqueue_task(mock_task, "Task1 ");
    enqueue_task(mock_task, "Task2 ");
    scheduler_run();

    TEST_ASSERT_EQUAL_STRING("Task1 Task2 ", result_buffer);
}

void test_queue_overflow() {
    clear_result_buffer();

    for (int i = 0; i < QUEUE_SIZE; i++) {
        bool success = enqueue_task(mock_task, "Task");
        if (i < QUEUE_SIZE - 1) {
            TEST_ASSERT_TRUE(success);
        } else {
            TEST_ASSERT_FALSE(success);  // Last enqueue should fail
        }
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_enqueue_and_execute_tasks);
    RUN_TEST(test_queue_overflow);
    return UNITY_END();
}
