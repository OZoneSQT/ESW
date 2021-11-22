// #include <stdio.h>#include "StudentList.h"
#include "Student.h"
// #include "List.h"
#include "StudentHandler.h"
#include "StudentList.h"

int main() {
    printf("Hello, World!\n");

    student_t student1;
    student1 = student_createStudent("dtttyrjrrgh", "dhtdte", 0, "yrsdkjyj");
    student_t student2;
    student2 = student_createStudent("zrdshyrddth", "rhgrsd", 1, "tgdjhulk");
    student_t student3;
    student3 = student_createStudent("dzrtyurhted", "zdrtyh", 2, "zsdrjhyh");

    studentList_t studentList;
    studentList = studentList_createStudentList(list_createList());
    studentHandler_t studentHandler = studentHandler_createStudentHandler(studentList);

    studentHandler_addStudent(studentHandler, student1);
    studentHandler_addStudent(studentHandler, student2);
    studentHandler_addStudent(studentHandler, student3);

    studentHandler_printAllStudentsInfo(studentHandler);

    student_t* studentGotten = studentHandler_searchStudentByLastName(studentHandler, "fgsd");
    student_printInfo(studentGotten);
    studentGotten = studentHandler_searchStudentById(studentHandler, 2);
    student_printInfo(studentGotten);
    studentHandler_printStudentInfo(studentHandler, studentGotten);

    int numNew = studentList_noOfStudents(studentList);
    printf("%d", numNew);
    studentList_removeStudent(studentList, student2);
    numNew = studentList_noOfStudents(studentList);
    printf("%d", numNew);

    return 0;
}