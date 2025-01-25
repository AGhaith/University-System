#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std ; 
class Course ; 

template<class T>
class StackNode{
    
    public:

    T Data  ;
    T* Dataaddress; 
    StackNode<T> *next = NULL ; 

    StackNode(T Data){ 
        this->Data = Data ;
    }
    
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

    T Pop(){
        
        // if (is_empty()){

        //     Course emptyCourse("EMPTY", "NULL", 0);
        //     cout << "Stack is empty" << endl ; 
        //     return emptyCourse ; 
        // }

        //else{

            StackNode<T> *temp = top ; 
            T course = top->Data ; 
            top = top->next ; 
            delete temp  ; 
            return course ;

//        }
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

    T get_top(){
        if (top==NULL){
            cout<< "stack is empty" << endl ;
            return top->Data ;
        }
        else{
            return top->Data ;
        } 

    }
    Stack<T> get_copy(){

        Stack<T> stack1 ;
        Stack<T> org_stack2 ; 

        while (!(*this).is_empty()){
            T x = (*this).Pop() ; 
            stack1.Push(x) ; 
            org_stack2.Push(x) ;
        }
        while (!org_stack2.is_empty() ){
            T x = org_stack2.Pop() ;
            stack1.Push(x) ; 
            (*this).Push(x) ; 
        }
        return stack1 ; 
        
    }
    

    ~Stack(){

        while(!is_empty()){

            Pop() ; 

        }
    }

};
#endif 