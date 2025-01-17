#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "SLL.h"
#include "Course.h"
using namespace std ;


int id=1;
class Student{

    private:

    int Student_id = 0 ; 
    string Student_name ="" ;
    string Email = "" ; 
    string Phone = "" ; 
    string Address = "" ; 
    string Password = "" ; 
    //SLL<Course> finished_courses ;

    public:
    Student(){
        
    }
    Student(string name , string Email , string Phone ,string Address , string Password){
        this->Student_id = id ;
        id++; 
        this->Student_name = name ; 
        this->Email = Email ;
        this->Phone = Phone ;
        this->Address = Address ; 
        this->Password = Password ;
    }
    
    int get_ID(){
        return Student_id ; 
    }
/*  
    void Add_Finshed_courses(Course course){

        finished_courses.insert(course);

    }
    void display_enrolled_courses(){

        finished_courses.display() ; 
    }*/
    string get_Name(){
        return Student_name ; 
    }
    string get_Email(){
        return Email ; 
    }
    string get_Phone(){
        return Phone ; 
    }
    string get_Address(){
        return Address ; 
    }
    string get_Password(){
        return Password ; 
    }
};

#endif
