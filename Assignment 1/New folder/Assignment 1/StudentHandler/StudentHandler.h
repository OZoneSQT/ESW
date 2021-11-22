#pragma once;

#include "Student.h"

struct StudentHandler {
    studentList_t studentList;
}StudentHandler;

typedef struct StudentHandler* studentHandler_t;
studentHandler_t studentHandler_createStudentHandler(studentList_t studentList);
void studentHandler_printStudentInfo(studentHandler_t self, student_t* student);
void studentHandler_printAllStudentsInfo(studentHandler_t self);
student_t* studentHandler_searchStudentById(studentHandler_t self, uint16_t studentId);
student_t* studentHandler_searchStudentByLastName(studentHandler_t self, char* lastName);
void studentHandler_addStudent(studentHandler_t self, student_t* student);