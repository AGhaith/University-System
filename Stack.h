#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std ; 
class Course ; 

template<class T>
class StackNode{
    
    public:

    T* Dataaddress; 
    StackNode<T> *next = NULL ; 
    
    StackNode(T* Data){ 
        this->Dataaddress = Data ;
    }
};

template <class T>
class Stack{

    private:

    StackNode<T> *top = NULL ; 

    public:

    void Push( T Data ){

        StackNode<T>* newnode = new StackNode<T>(Data) ; 

        if (is_empty()){

            top = newnode ;
            return;
        }
        else {
            newnode->next = top ;  
            top = newnode ; 
        }
    }
        void PushWithAddress( T *Data ){

        StackNode<T>* newnode = new StackNode<T>(Data) ; 

        if (is_empty()){

            top = newnode ;
            return;
        }
        else {
            newnode->next = top ;  
            top = newnode ; 
        }
    }

    bool is_empty(){

        return top==NULL;
    }
T* Pop() {
    if (is_empty()) {
        cout << "Stack is empty" << endl;
        return NULL;
    } else {
        StackNode<T>* temp = top;
        T* course = top->Dataaddress;
        top = top->next;
        delete temp;
        return course;
    }
}
    T* Peek(){
        if (is_empty()) return NULL;
        else return top->Dataaddress ;
    }
    Stack<T> get_copy(){
        return *this;
    }
};
#endif 