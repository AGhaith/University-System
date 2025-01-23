#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std ; 
class Course ; 

template<class T>
class StackNode{
    
    public:

    T Data  ; 
    StackNode<T> *next = NULL ; 

    StackNode(T Data){
        
        this->Data = Data ;

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

    T Pop(){
        Course emptyCourse("EMPTY", "NULL", 0); 
        if (is_empty()){
            return emptyCourse ; 
        }
        else{

            StackNode<T> *temp = top ; 
            T course = top->Data ; 
            top = top->next ; 
            delete temp  ; 
            return course ;
       }
    }

    T Peek(){

        if (is_empty()){

            return -1 ; 

        }
        
        else{

            return top->Data ;

        }
    }

    bool is_empty(){

        if (top == NULL){

            return true ; 

        }
        
        else{

            return false ; 

        }
    }
    
    Stack<T> get_copy()const{
        return *this ; 
    }
    

    ~Stack(){

        while(!is_empty()){

            Pop() ; 

        }
    }

};
#endif 