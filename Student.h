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
    SLL<Course> finished_courses ;

    public:

    Student(string name){
        this->Student_id = id ;
        id++; 
        this->Student_name = name ; 
    }
    void Finshed_courses(Course course){

        finished_courses.insert(course);

    }
    int get_ID(){
        return Student_id ; 
    }
    void display_enrolled_courses(){

        finished_courses.display() ; 
    }
};

#endif
