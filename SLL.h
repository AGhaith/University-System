#ifndef SLL_H
#define SLL_H
#include <iostream>
class Student;
using namespace std ;

template<class T>
class SLLNode{

public:
    T Data;
    SLLNode* next = NULL;

    SLLNode(T Data){
        this->Data = Data ; 
    }

};
template <class T>
class SLL{
    private :
        SLLNode<T>* head = NULL ;
    public:
    //overriding bool operator in students and courses so that when comparing student to student the comparison is done by id
    bool Find(T x){
        SLLNode<T>*curr = head;
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
        SLLNode<T>*curr = head;
        while(curr!=NULL){
            if (curr->Data.Get_ID() == x){
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

        SLLNode<T>* newnode = new SLLNode<T>(mydata) ; 

        if (head==NULL){

            head = newnode ; 
        }
        else{

            SLLNode<T>* temp = head ; 
            while (temp->next != NULL){
                temp = temp->next ;
            }
            temp->next = newnode ; 
        }

    }
    void Display_Student_Records(){
        SLLNode<T> *curr = head ;

        if (head == NULL){

            cout << "no items..." << endl ; 
        }

        else{

            while (curr != NULL){
                cout << "-------------------------------------------------------------" << endl;
                cout << curr->Data.Get_ID() << "  ||  " << curr->Data.Get_First_Name() << " " << curr->Data.Get_Last_Name() << "  ||  " << curr->Data.Get_Email() << "  ||  " << curr->Data.Get_Phone() << "  ||  " << curr->Data.Get_Address() << curr->Data.Get_Password() << endl ;
                curr=curr->next;
            }
            cout << "-------------------------------------------------------------" << endl;
        }
    }
    bool checkuserinfo(string email,string password,Student *&x){
    email = lower(email);
    SLLNode<T>*curr = head;
    if (curr == NULL){
        return false;
    }
    

        while(curr!=NULL){
        string compare = lower(curr->Data.Get_Email());
            if (compare == email){
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL){
            return false;
        }else {
            if(curr->Data.Get_Password() == password){
            x=&(curr->Data);
            return true;
            }
            return false;
        }
    
    }
    void deleteStudent(int id){
    if (head == NULL){
        cout << "There are no students" << endl;
        return;
    }
    SLLNode<T> *curr = head;
    if (curr->Data.Get_ID() == id){
        head=curr->next;
        delete curr;
        return;
    }
    while(curr->next != NULL){
    if (curr->next->Data.Get_ID() == id){
        break;
    }   
    curr = curr->next; 
    } 
    SLLNode<T> *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    }
};

#endif