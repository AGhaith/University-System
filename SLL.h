#ifndef SLL_H
#define SLL_H

#include <iostream>
class Student;
using namespace std ;


class Node{

public:
    Student StudentData;
    Node* next = NULL;

    Node(Student Data){
        this->StudentData = Data ; 
    }

};

class SLL{
    private :
        Node* head = NULL ;
    public:

    
    void insert(Student mydata){

        Node* newnode = new Node(mydata) ; 

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
                cout << curr->StudentData.get_ID() << "  ||  " << curr->StudentData.get_Name() << "  ||  " << curr->StudentData.get_Email() << "  ||  " << curr->StudentData.get_Phone() << "  ||  " << curr->StudentData.get_Address() << curr->StudentData.get_Password() << endl ;
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
    if (curr->StudentData.get_ID() == id){
        head=curr->next;
        delete curr;
        return;
    }
    while(curr->next != NULL){
    if (curr->next->StudentData.get_ID() == id){
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