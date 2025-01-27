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
    void Add_student(Student *mystudent){
        SLL_Students.insert_with_pointer(mystudent) ;
        selection_sorting();
    }
    void Delete_Student(int ID){
        SLL_Students.deleteStudent(ID) ; 
    }
    void display(){
        SLL_Students.Display_Student_Records();
    }
    bool check(string email,string password,Student *&x){
        return SLL_Students.checkuserinfo(email,password,x);
    }
    void selection_sorting(){
        SLL_Students.selection_sort();
    }
};


#endif