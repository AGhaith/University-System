#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "helper.cpp"
#include "Course Registration.h"
#include "Course waitlist.h"

using namespace std;
class Student ;

class Course {
private:
    int CourseID, CourseCredits ,course_seats ;
    string CourseName, CourseInstructor;
    Stack<Course> Prerequisites ; 
    CourseWaitlist<Student> Waitlist;

public:
    Course(string name = "", string instructor = "", int credits = 0 , int maxstudents = 0  ) {
        CourseID = Course_ID_Counter;
        Course_ID_Counter++;
        CourseName = name;
        CourseInstructor = instructor;
        CourseCredits = credits;
        course_seats = maxstudents;

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
    int get_seats(){
        return course_seats;
    }
    void add_to_waitlist(Student &student){
        Waitlist.enqueueStudent(student);
    }
    void dequeue_from_waitlist(){
        Waitlist.dequeueStudent();
    }
    void stundent_enrolled(){
        course_seats--;
    }
    void showrequiredcourses(){
        Stack<Course> temp = Prerequisites.copy();
        cout << "Required courses for " << CourseName << ":" << endl;
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
    Stack<Course> getcopy()const{
        return Prerequisites.copy();
    }

};


#endif // COURSE_H
