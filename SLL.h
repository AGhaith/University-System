#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std ;

template <class T >
class Node{

    public:

    T Data;
    Node* next = NULL;

    Node(T Data){
        this->Data = Data ; 
    }

};

template <class T>
class SLL{

    public:

    Node<T>* head = NULL ;
    
    void insert(T Data){

        Node<T>* newnode = new Node<T>(Data) ; 

        if (head==NULL){

            head = newnode ; 
        }
        else{

            Node<T>* temp = head ; 
            while (temp->next != NULL){
                temp = temp->next ;
            }
            temp->next = newnode ; 
        }

    }
    void display(){
        Node<T> *curr = head ;

        if (head == NULL){

            cout << "no items..." << endl ; 
        }

        else{

            while (curr != NULL){

                cout << curr->data.get_name() << "||" ;
            }
        }
    }
};

#endif