// unity.h
#ifndef UNITY_H
#define UNITY_H

#include <stdio.h>
#include <stdlib.h>

#define UNITY_VERSION "2.5.0"

void UnityBegin(const char* filename);
void UnityEnd(void);
void UnityAssertEqualInt(int expected, int actual, const char* message, int line);
void UnityAssertEqualString(const char* expected, const char* actual, const char* message, int line);
void UnityAssertEqualFloat(float expected, float actual, const char* message, int line);
void UnityAssertTrue(int condition, const char* message, int line);

#endif // UNITY_H