#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std ; 

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

        }
        else {

            newnode->next = top ;  
            top = newnode ; 

        }
    }

    void Pop(){
        
        if (is_empty()){

            cout << "Stack is empty" << endl ; 

        }

        else{

            StackNode<T> *temp = top ; 
            top = top->next ; 
            //top removed han3ml eh baadeha ? ,,return ?
            delete temp  ; 

        }

    }

    T Peek(){

        if (is_empty()){

            cout << "Stack is empty" << endl ;

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

    ~Stack(){

        while(!is_empty()){

            Pop() ; 

        }
    }

};
#endif 