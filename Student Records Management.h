#ifndef STUDENT_RECORD_MANGMENT_H
#define STUDENT_RECORD_MANGMENT_H

#include <iostream>
#include "SLL.h"
#include "Course.h"
#include "Student.h"
using namespace std ;

class Student_Records_Management{
    private:
    SLL SLL_Students ; 
    public:
    void Add_student(Student mystudent){
        SLL_Students.insert(mystudent) ; 
    }
    void Delete_Student(int ID){
        SLL_Students.deleteStudent(ID) ; 
    }
    void display(){
        SLL_Students.display();
    }
};


#endif