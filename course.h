#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Stack.h"
#include "helper.cpp"
using namespace std;
class Student ;
class Course {
private:
    int CourseID, CourseCredits;
    string CourseName, CourseInstructor;
    Stack<Course> Prerequisites ; 

public:
    Course(string name = "", string instructor = "", int credits = 0) {
        CourseID = Course_ID_Counter;
        Course_ID_Counter++;
        CourseName = name;
        CourseInstructor = instructor;
        CourseCredits = credits;
        Stack<Course> Prerequisites;
    }

    int get_ID() {
        return CourseID;
    }

    string get_name() {
        return CourseName;
    }

    string get_instructor() {
        return CourseInstructor;
    }

    int get_credits() {
        return CourseCredits;
    }
   
    bool operator==(Course other) const {
        return this->CourseID == other.CourseID ;
    }

    void add_to_Prerequisites( Course must_be_finished_course){
        Prerequisites.Push(must_be_finished_course);
    }

    bool check_Prerequisites(Student student ){
        
        Stack copy_prerq = Prerequisites.get_copy() ; 

        while (!copy_prerq.is_empty()){

            Course curr_course = copy_prerq.get_top();

            if (student.searchWithHashing(curr_course)){
                copy_prerq.Pop();
            }
            else{
                cout <<"///" << endl ; 
                return false;
            }
        }

        if(!copy_prerq.is_empty()){
            return false ; // lesa feha courses makhlshasah
        }
        return true;
    }
};


#endif // COURSE_H
