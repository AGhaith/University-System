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
    void showrequiredcourses(){
        Stack<Course> temp = Prerequisites;
        while (!temp.is_empty()){
            cout << temp.Pop().get_name() << endl;
        }
    }
    bool operator==(Course other) const {
        return this->CourseID == other.CourseID ;
    }

    void add_to_Prerequisites( Course must_be_finished_course){
        Prerequisites.Push(must_be_finished_course);
    }
Stack<Course> getcopy(){
    return Prerequisites;
}

};


#endif // COURSE_H
