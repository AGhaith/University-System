#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "Course.h" // Include full definition of Course
#include "Person.h"
#include "SLL.h"    // Include full definition of SLL
using namespace std ;


int Student_ID_Counter=1;

class Student:public Person{

    private:

    int Student_id; 
    unordered_map<int,SLL<Course>> FinishedCoursesHashmap;
    string suffix = "@nu.edu.eg";
    public:
    Student(){

    }
    Student(string first_name, string last_name , string Phone ,string Address , string Password){
        this->Student_id = Student_ID_Counter ;
        Student_ID_Counter++; 
        this->First_name = first_name ; 
        this->Last_name = last_name ; 
        this->Email = first_name[0]+last_name+suffix;
        this->Phone = Phone ;
        this->Address = Address ; 
        this->Password = Password ;
    }
    
    int Get_ID(){
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
