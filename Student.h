#ifndef STUDENT_H
#define STUDENT_H

#include "Student Records Management.h"
#include "Course.h"
#include <iostream>
#include <unordered_map>
#include <string> // Include full definition of SLL
using namespace std ;
class Person{
    protected:
    string First_name  ;
    string Last_name;
    string Email  ; 
    string Phone  ; 
    string Address  ; 
    string Password  ; 
    public:
    string Get_First_Name(){
        return First_name ; 
    }
    string Get_Last_Name(){
        return Last_name ; 
    }
    string Get_Email(){
        return Email ; 
    }
    string Get_Phone(){
        return Phone ; 
    }
    string Get_Address(){
        return Address ; 
    }
    string Get_Password(){
        return Password ; 
    }  
Person() : First_name(""), Last_name(""), Email(""), Phone(""), Address(""), Password("") {}
virtual ~Person() {}

    

};


class Student:public Person{

    private:

    int Student_id; 
    SLL<Course> RegisteredCourses;
    unordered_map<int,SLL<Course>> FinishedCoursesHashmap;
    string suffix = "@nu.edu.eg";
    string dot = ".";
    int NumberOfEnrolledCourses=0;

    public:
    Student(){

    }
    Student(string first_name, string last_name , string Phone ,string Address , string Password){
        this->Student_id = Student_ID_Counter ;
        Student_ID_Counter++; 
        this->First_name = first_name ; 
        this->Last_name = last_name ; 
        this->Email = first_name[0]+dot+last_name+to_string((Student_id/10)%10)+to_string(Student_id%10)+suffix;
        this->Phone = Phone ;
        this->Address = Address ; 
        this->Password = Password ;
    }
    
    int Get_ID(){
        return Student_id ; 
    }
    void add_course(){
        NumberOfEnrolledCourses++;
    }
    void withdraw_course(Course course){
        NumberOfEnrolledCourses--;
    }
    int Get_Number_Of_Enrolled_Courses(){
        return NumberOfEnrolledCourses;
    }
    Course FindCourseByNumber(int Course_To_Find){
        return RegisteredCourses.FindCourseByNumber(Course_To_Find);
    }
    SLL<Course> *getRegisteredCourses(){
        return &RegisteredCourses;
    }
    unordered_map<int,SLL<Course>> *getFinishedCourses(){
        return &FinishedCoursesHashmap;
    }
    void add_to_finished_courses(Course *course){
        FinishedCoursesHashmap[course->get_ID()].insert(course);
    }
    void Display_Enrolled_Courses(){
        RegisteredCourses.Display_Courses();
    }
    /*void display_enrolled_courses(){

        finished_courses.display() ; 
    }*/
    
    bool operator==(Student other) const {
        return this->Student_id == other.Student_id ;
    }

};

#endif
