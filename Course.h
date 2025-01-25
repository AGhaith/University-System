#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Stack.h"
#include "helper.cpp"
#include "Course waitlist.h"
using namespace std;
class Student ;
class Course {
private:
    // Each Course Contains ID(Auto,atically assigned) , Credits , Name , Instructor and its prerequisite courses
    int CourseID, CourseCredits , course_seats;
    string CourseName, CourseInstructor;
    Stack<Course> Prerequisites ;
    CourseWaitlist<Student>* Waitlist;
 

public:
    // Constructor
    Course(string name = "", string instructor = "", int credits = 0 , int seats = 0) {
        CourseID = Course_ID_Counter;
        Course_ID_Counter++;
        CourseName = name;
        CourseInstructor = instructor;
        CourseCredits = credits;
        course_seats = seats;
        Waitlist->set_maxSize(seats);
    }
//Getters
    int Get_ID() {
        return CourseID;
    }
    string Get_Name() {
        return CourseName;
    }
    string Get_Instructor() {
        return CourseInstructor;
    }
    int Get_Credits() {
        return CourseCredits;
    }
    //Show All Prerequsites for a certain course
    void List_Prerequisites(){
        // Takes a copy of the stack to pervent manipulation in the original Stack 
        Stack<Course> temp = Prerequisites;
        while (!temp.is_empty()){
            cout << temp.Pop()->Get_Name() << endl;
        }
    }
    void Add_To_Prerequisites( Course *must_be_finished_course){
        Prerequisites.PushWithAddress(must_be_finished_course);
    }
    //Useless Function that sends a copy of the prerequisite stack to prevent editing in the origical stack
    Stack<Course> Get_Copy_Of_Prerequisite_Stack(){
        return Prerequisites;
    }
    //Overriding Operator to make (==) Compare the Course ID as no two courses can have the same ID
    bool operator==(Course other) const {
        return this->CourseID == other.CourseID ;
    }
    void add_to_waitlist(Student *student){
        Waitlist->enqueueStudent(student);
    }
    void dequeue_from_waitlist(){
        Waitlist->dequeueStudent();
    }
    void stundent_enrolled(){
        course_seats--;
    } 
};


#endif // COURSE_H
