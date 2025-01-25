#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Stack.h"
#include "helper.cpp"
using namespace std;
class Student;


template<class T>
class QueueNode{
    public:
    QueueNode<T> * Next ; 
    Student *Data ;

    QueueNode<T>(Student *Data){
        Next = NULL ; 
        this->Data = Data ; 
    }
};
template<class T>
class CourseWaitlist {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;
    int Size;

public: 
    CourseWaitlist()
    {
        front=nullptr;
        rear=nullptr;
        Size=0;
    }
    void enqueueStudent(Student *student) {

        QueueNode<T>* newNode = new QueueNode<T>(student);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->Next = newNode;
            rear = newNode;
        }

        Size++;
    }


    Student* dequeueStudent(Course *x) {
        if (front == nullptr) {
            cout << "Waitlist is empty!" << endl;
            return NULL;
        }
        QueueNode<T>* temp = front;
        Student* temp2 = temp->Data;
        front = front->Next;
        delete temp;
        Size--;

        if (front == NULL) {
            rear = NULL;
        }
        return temp2;
    }

    void displayWaitlist() {
        if (front == NULL) {
            printRed("No students are currently on the waitlist.");
            return;
        }

        cout << "Waitlist:" << endl;
        QueueNode<T>* current = front;
        while (current != NULL) {
            cout << current->Data->Get_First_Name() << " " <<current->Data->Get_Last_Name() << " || ";
            current = current->Next;
        }
        cout << endl ; 
    }
    int get_size(){
        return Size;
    }
    bool is_empty(){
        return front == NULL;
    }
};
class Course {
private:
    // Each Course Contains ID(Auto,atically assigned) , Credits , Name , Instructor and its prerequisite courses
    int CourseID, CourseCredits , course_seats;
    string CourseName, CourseInstructor;
    Stack<Course> Prerequisites ;
    CourseWaitlist<Student> Waitlist;
    int taken_seats=0;


public:
    // Constructor
    Course(string name = "", string instructor = "", int credits = 0 , int seats = 0) {
        CourseID = Course_ID_Counter;
        Course_ID_Counter++;
        CourseName = name;
        CourseInstructor = instructor;
        CourseCredits = credits;
        course_seats = seats;
    }
//Getters
    int Get_Available_seats(){
        return course_seats-taken_seats;
    }
    bool check_seats(){
        if (this->Get_Available_seats() == 0){
            printRed("Course is full");
            cout << endl;
            return false;
        }
        return true;
    }
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
            Course *temptemp = temp.Pop();
            if (temptemp !=NULL)
            cout << temptemp->Get_Name() << endl;
        }
    }
    void Add_To_Prerequisites( Course *must_be_finished_course){
        Prerequisites.PushWithAddress(must_be_finished_course);
    }
    //Useless Function that sends a copy of the prerequisite stack to prevent editing in the origical stack
    Stack<Course> Get_Copy_Of_Prerequisite_Stack(){
        return Prerequisites;
    }
    int How_Many(){
        return Waitlist.get_size();
    }
    //Overriding Operator to make (==) Compare the Course ID as no two courses can have the same ID
    bool operator==(Course other) const {
        return this->CourseID == other.CourseID ;
    }
    void add_to_waitlist(Student *student){
        Waitlist.enqueueStudent(student);
    }
    Student* dequeue_from_waitlist(){
        return Waitlist.dequeueStudent(this);
    }


};


#endif // COURSE_H
