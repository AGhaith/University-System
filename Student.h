#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "Course.h" // Include full definition of Course
#include "Person.h"
#include "SLL.h"    // Include full definition of SLL
using namespace std ;



class Student:public Person{

    private:

    int Student_id; 
    SLL<Course> RegisteredCourses;
    SLL<Course> Waitlist;
    unordered_map<int,SLL<Course>> FinishedCoursesHashmap;
    string suffix = "@nu.edu.eg";
    string dot = ".";
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
    void RegisterCourse(Course Course_To_Register){
        RegisteredCourses.insert(Course_To_Register);
    }
    void Display_Enrolled_Courses(){
        RegisteredCourses.Display_Courses();
    }
    int hashing(Course mycourse){
        int final = 0;
        string a = mycourse.get_name();
        for(int i = 0 ; i < a.length() ; i++){
            int temp = a[i];
            if (i-1==a.length()){
                final = final + temp*2;
            }else {
                final+=a[i];
            }
        }
        return final;

    }
    void Add_To_Finshed_courses(Course mycourse){

        FinishedCoursesHashmap[hashing(mycourse)].insert(mycourse);

    }
    // Look up courses with hashtable
    bool searchWithHashing(Course x){
        int index = hashing(x);
        return FinishedCoursesHashmap[index].Find(x);
    }
    /*void display_enrolled_courses(){

        finished_courses.display() ; 
    }*/
    
    bool operator==(Student other) const {
        return this->Student_id == other.Student_id ;
    }

};

#endif
