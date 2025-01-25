#ifndef COURSE_WAITLIST_H
#define COURSE_WAITLIST_H

#include <iostream>
using namespace std ;

class Student ; 

template<class T>
class QueueNode{
    public:
    QueueNode<T> * Next ; 
    T Data ;

    QueueNode(T Data){
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
    int maxSize = 0 ;

public:
    CourseWaitlist()
    {
        front=nullptr;
        rear=nullptr;
        Size=0;
    }
    void set_maxSize(int max){
        maxSize = max ;
        return ;
    }
    void enqueueStudent(T student) {
        if (Size == maxSize) {
            cout << "Waitlist is full! Cannot add any more students." << endl;
            return;
        }

        QueueNode<T>* newNode = new QueueNode<T>(student);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->Next = newNode;
            rear = newNode;
        }

        Size++;
    }

    void dequeueStudent() {
        if (front == nullptr) {
            cout << "Waitlist is empty!" << endl;
            return;
        }

        front->Data.RegisterCourse() ;

        QueueNode<T>* temp = front;
        front = front->Next;
        delete temp;
        Size--;


        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "The first student on the waitlist has been enrolled." << endl;
    }

    void displayWaitlist() {
        if (front == nullptr) {
            cout << "No students are currently on the waitlist." << endl;
            return;
        }

        cout << "Waitlist:" << endl;
        QueueNode<T>* current = front;
        while (current != nullptr) {
            cout << current->Data.Get_First_Name() << " " <<current->Data.Get_Last_Name() << " || ";
            current = current->Next;
        }
        cout << endl ; 
    }
};

#endif