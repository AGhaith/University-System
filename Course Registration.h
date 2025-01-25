#ifndef COURSE_REGESTRATION_H
#define COURSE_REGESTRATION_H

#include <iostream>

#include "Course.h"
#include "Student.h"

using namespace std; 

template<class T>
class StackNode {
public:
    T Data;
    StackNode<T>* next = NULL;

    StackNode(T Data) {
        this->Data = Data;
    }
};

template <class T>
class Stack {
private:
    StackNode<T>* top = NULL;

public:
    void Push(T Data) {
        StackNode<T>* newnode = new StackNode<T>(Data);
        if (is_empty()) {
            top = newnode;
            return;
        }
        else {
            newnode->next = top;
            top = newnode;
        }
    }

    T Pop() {
        Course emptyCourse("EMPTY", "NULL", 0 , 0);
        if (is_empty()) {
            return emptyCourse;
        }
        else {
            StackNode<T>* temp = top;
            T course = top->Data;
            top = top->next;
            delete temp;
            return course;
        }
    }

    T Peek() {
        if (is_empty()) {
            return -1;
        }
        else {
            return top->Data;
        }
    }

    bool is_empty() {
        return top == NULL;
    }

    void Display() {
        StackNode<T>* curr = top;
        while (curr != NULL) {
            cout << curr->Data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    Stack<T> copy()const{
        Stack<T> s1; 
        Stack<T> org ;
        StackNode<T> *curr = top ;
        while(curr!=NULL){
            org.Push(curr->Data);
            curr=curr->next ;
        }
        while(!(org.is_empty())){ 
            T x = org.Pop() ; 
            s1.Push(x);
        }
        return s1 ; 
    }
    ~Stack() {
        while (!is_empty()) {
            Pop();
        }
    }
};
template <class T>
class Course_Regestraion{

    private:

    Stack<T> prerequisites;

    public:

    void add_to_Prerequisites( Course must_be_finished_course){
        Prerequisites.Push(must_be_finished_course);
    }

    void showrequiredcourses(){
        Prerequisites.Display();
    }
    bool check_seats(Course *course){
        if (course->get_seats() == 0){
            printRed("Course is full");
            cout << endl;
            return false;
        }
        return true;
    }
    bool if_already_registered(Course *course , Student *student){
        if (student->getRegisteredCourses->Find(course))// SLL
        {
            printRed("student already registered");
            cout << endl; 
            return false ;
        }
        return true;
    }
    bool check_Prerequisites(Course *course , Student *student){//hash
        Stack<Course> copy_prerq = course->getcopy() ; 
        unordered_map<int,SLL<Course>> hashmap = student->getFinishedCourses() ;
        while (!copy_prerq.is_empty()){
            StackNode<Course> curr_course = copy_prerq->Pop();
            if (!(hashmap.searchWithHashing(curr_course.Data))){
                cout << "student didnt finish all courses" << endl ;
                return false ; 
            }
            curr_course = curr_course->Next ; //errpr here
        }
        return true;
    }
    bool validation_for_course(Course *course , Student *student){
        bool flag1 = if_already_registered(course , student);
        bool flag2 = check_Prerequisites(course , student );
        bool flag3 = check_seats(course);
        if(flag1 && flag2 && flag3){
            
            student->getRegisteredCourses()->insert(&course);
            student->add_course();
            cout <<"student succefully enrolled " << endl ;
            return true  ;
        }
        else{
            return false ;
    }
    }
    bool WithdrawCourse(Course *Course_To_Withdraw , Student *student){
        bool temp = student->Delete_Course(Course_To_Withdraw);
        if (temp) {
            student->withdraw_course()--;
            Course_To_Withdraw->dequeue_from_waitlist(Course_To_Withdraw);
            return temp;
        }
        return temp;
    }
};
#endif
