#ifndef SLL_H
#define SLL_H

#include <iostream>
class Student;
using namespace std ;

template<class T>
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
    private :
        Node<T>* head = NULL ;
    public:
    //overriding bool operator in students and courses so that when comparing student to student the comparison is done by id
    bool Find(T x){
        Node<T>*curr = head;
        while(curr!=NULL){
            if (curr->Data == x){
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL){
            return false;
        }else {
            return true;
        }

    }
    //If given ID
    bool Find_By_ID(int x){
        Node<T>*curr = head;
        while(curr!=NULL){
            if (curr->Data->get_ID() == x){
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL){
            return false;
        }else {
            return true;
        }

    }
    void insert(T mydata){

        Node<T>* newnode = new Node<T>(mydata) ; 

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
    void Display_Student_Records(){
        Node<T> *curr = head ;

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
    Node<T> *curr = head;
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
    Node<T> *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    }
};

#endif