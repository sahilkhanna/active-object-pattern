cmake_minimum_required(VERSION 3.10)
project(ActiveObjectPattern C)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)
include_directories(tests/unity/src)
include_directories(tests/unity)

# Source files for the main application
set(SRC_FILES
    src/active_object.c
    src/main.c
)

# Source files for the unit tests
set(TEST_SRC_FILES
    tests/test_active_object.c
    src/active_object.c
    tests/unity/src/unity.c
)

# Define the main application target
add_executable(active_object ${SRC_FILES})

# Define the unit test target
add_executable(test_runner ${TEST_SRC_FILES})

# Add a custom target to run the unit tests
add_custom_target(run_tests
    COMMAND test_runner
    DEPENDS test_runner
    COMMENT "Running unit tests..."
)

# Add a clean target to remove build artifacts
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} --build . --target clean
    COMMAND ${CMAKE_COMMAND} -E remove -f active_object test_runner
    COMMENT "Cleaning up build artifacts..."
)