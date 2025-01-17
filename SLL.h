#ifndef SLL_H
#define SLL_H

#include <iostream>
#include"Student.h"
using namespace std ;


class Node{

    public:

    Student Data;
    Node* next = NULL;

    Node(Student Data){
        this->Data = Data ; 
    }

};

class SLL{

    public:

    Node* head = NULL ;
    
    void insert(Student Data){

        Node* newnode = new Node(Data) ; 

        if (head==NULL){

            head = newnode ; 
        }
        else{

            Node* temp = head ; 
            while (temp->next != NULL){
                temp = temp->next ;
            }
            temp->next = newnode ; 
        }

    }
    void display(){
        Node *curr = head ;

        if (head == NULL){

            cout << "no items..." << endl ; 
        }

        else{

            while (curr != NULL){
                cout << "-------------------------------------------------------------" << endl;
                cout << curr->Data.get_ID() << "  ||  " << curr->Data.get_Name() << "  ||  " << curr->Data.get_Email() << "  ||  " << curr->Data.get_Phone() << "  ||  " << curr->Data.get_Address() << curr->Data.get_Password() << endl ;
                curr=curr->next;
            }
            cout << "-------------------------------------------------------------" << endl;
        }
    }
    void deleteStudent(int id){
    if (head == NULL){
        cout << "There are no students" << endl;
        return;
    }
    Node *curr = head;
    if (curr->Data.get_ID() == id){
        head=curr->next;
        delete curr;
        return;
    }
    while(curr->next != NULL){
    if (curr->next->Data.get_ID() == id){
        break;
    }   
    curr = curr->next; 
    } 
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    }
};

#endif