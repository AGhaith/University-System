#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "Course.h" // Include full definition of Course
#include "SLL.h"    // Include full definition of SLL
using namespace std ;


int Student_ID_Counter=1;

class Student{

    private:

    int Student_id; 
    string Student_name  ;
    string Email  ; 
    string Phone  ; 
    string Address  ; 
    string Password  ; 
    unordered_map<int,SLL<Course>> FinishedCoursesHashmap;
    public:
    Student(){

    }
    Student(string name , string Email , string Phone ,string Address , string Password){
        this->Student_id = Student_ID_Counter ;
        Student_ID_Counter++; 
        this->Student_name = name ; 
        this->Email = Email ;
        this->Phone = Phone ;
        this->Address = Address ; 
        this->Password = Password ;
    }
    
    int get_ID(){
        return Student_id ; 
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
    bool LookUp_Course_In_Hashtable(Course x){
        int index = hashing(x);
        return FinishedCoursesHashmap[index].Find(x);
    }
    /*void display_enrolled_courses(){

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
