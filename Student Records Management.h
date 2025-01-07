#ifndef STUDENT_RECORD_MANGMENT_H
#define STUDENT_RECORD_MANGMENT_H

#include <iostream>
#include "SLL.h"
#include "Course.h"
#include "Student.h"
using namespace std ;

class Student_Records_Management{
    private:
    SLL<Student> SLL_Students ; 
    public:
    void Add_student(string name , string Email , string Phone ,string Address , string Password){

        Student s1(name , Email , Phone , Address , Password) ; 
        SLL_Students.insert(s1) ; 
    }
    void Delete_Student(int ID){
        SLL_Students.deleteStudent(ID) ; 
    }
};


#endif