#pragma once;

#include <stdint.h>

typedef struct Student {
    char firstName[25];
    char lastName[25];
    uint16_t studentID;
    char nationality[25];
}Student;

typedef struct Student* student_t;
student_t* student_createStudent(char* firstName, char* lastName, uint16_t studentId, char* nationality);
void student_printInfo(student_t self);
uint16_t student_getId(student_t self);
char* student_getLastName(student_t self);