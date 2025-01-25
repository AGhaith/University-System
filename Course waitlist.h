#ifndef COURSE_WAITLIST_H
#define COURSE_WAITLIST_H

#include <iostream>
using namespace std ;

#include "Student.h" 

template<class T>
class QueueNode{
    public:
    QueueNode<T> * Next ; 
    T *Data ;

    QueueNode(T *Data){
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
    void enqueueStudent(T *student) {

        QueueNode<T> newNode = new QueueNode<T>(student);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->Next = newNode;
            rear = newNode;
        }

        Size++;
    }

    void dequeueStudent(Course x) {
        if (front == nullptr) {
            cout << "Waitlist is empty!" << endl;
            return;
        }

        front->Data->RegisterCourse(x) ;

        QueueNode<T>* temp = front;
        front = front->Next;
        delete temp;
        Size--;


        if (front == NULL) {
            rear = NULL;
        }
        printBlue("The first student on the waitlist has been enrolled.");
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
    bool is_empty(){
        return front == NULL;
    }
};

#endif