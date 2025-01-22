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
    void Add_student(Student mystudent){
        SLL_Students.insert(mystudent) ; 
    }
    void Add_Course(Student mystudent , Course x){
        mystudent.Add_To_Finshed_courses(x);
        cout << "Course " << x.get_name() << " Successfully Added to " << mystudent.Get_First_Name() << " " << mystudent.Get_Last_Name() << "'s " << "Transcript" << endl;
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
};


#endif