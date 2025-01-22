#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std ;

template<class T>
class DLLNode{

    public:
    DLLNode * next ; 
    DLLNode * prev ;
    T data ; 

    DLLNode( T data ){
        next = NULL ; 
        prev = NULL ; 
        this->data = data ;
    }

};

template<class T>
class DLL{

    private:
    DLLNode<T> *head = NULL ;
    DLLNode<T> *tail = NULL ;

    public:

    void add( T data ){
        DLLNode<T> *newnode = new DLLNode<T>( data )  ;

        if (head == 0 ){
            head = newnode ;
        }
        else{
            newnode->prev = tail ;
            tail->next = newnode ; 
            tail = newnode ; 
    }
        cout <<"course added succecfully" << endl ;
    }
    void view(){    

        DLLNode<T> *curr = head  ; 

        cout << "enrollment history" ; 
        while ( curr != NULL){
            curr = curr->next ;
            cout << curr->data << " , " ; 
        }
        cout << endl ; 
    }


} ; 

#endif 