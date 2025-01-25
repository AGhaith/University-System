#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>
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
        if (curr == NULL){
            return;
        }
        cout << "Enrollment history" ; 
        while ( curr != NULL){
            cout << curr->data << " , " ; 
            curr = curr->next ;
        }
        cout << endl ; 
    }
} ; 

class Course_Enrollment_History{

    private:

    DLL<Course> Course_Enrollment_history ;

    public:

    void add(Course course_to_enroll){
        Course_Enrollment_history.add(course_to_enroll) ; 
    }

    void view(){
        Course_Enrollment_history.view() ; 
    }
};
#endif 