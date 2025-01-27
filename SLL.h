#ifndef SLL_H
#define SLL_H
#include "Course.h"
#include <iostream>
class Student;
class Course;
using namespace std ;

template<class T>
class SLLNode{

public:
    T Data;
    T* Dataaddress;
    SLLNode* next = NULL;

    SLLNode(T Data){
        this->Data = Data ; 
    }
    SLLNode(T* Data){
        this->Dataaddress = Data ; 
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
    bool Findinaddress(T *x){
        SLLNode<T>*curr = head;
        while(curr!=NULL){
            if (*(curr->Dataaddress) == *x){
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
        void insert_with_pointer(T *mydata){

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
    void Display_Courses(){
        int counter = 1;
        if (head == NULL) {
            cout << "No Enrolled Courses" << endl;
            return;
        }
        SLLNode<Course> *curr = head;
        while (curr != NULL){
        cout << counter << '.' << curr->Dataaddress->Get_Name() << endl;
        counter++;
        curr=curr->next;
        }
    }
    void Display_Student_Records(){
        SLLNode<T> *curr = head ;

        if (head == NULL){

            cout << "no items..." << endl ; 
        }

        else{

            while (curr != NULL){
                cout << "--------------------------------------------------------------------------------------------" << endl;
                cout << curr->Dataaddress->Get_ID() << "  ||  " << curr->Dataaddress->Get_First_Name() << " " << curr->Dataaddress->Get_Last_Name() << "  ||  " << curr->Dataaddress->Get_Email() << "  ||  " << curr->Dataaddress->Get_Phone() << "  ||  " << curr->Dataaddress->Get_Address() <<  "  ||  " << curr->Dataaddress->Get_Password() <<  "  ||  "<< curr->Dataaddress->Get_ID() << endl ;
                curr=curr->next;
            }
            cout << "--------------------------------------------------------------------------------------------" << endl;
        }
    }
    bool checkuserinfo(string email,string password,Student *&x){
    email = lower(email);
    SLLNode<T>*curr = head;
    if (curr == NULL){
        return false;
    }
    

        while(curr!=NULL){
        string compare = lower(curr->Dataaddress->Get_Email());
            if (compare == email){
                break;
            }
            curr = curr->next;
        }
        if (curr == NULL){
            cout << "Couldn't Find Email" << endl;
            return false;
        }else {
            if(curr->Dataaddress->Get_Password() == password){
            x=(curr->Dataaddress);
            return true;
            }
            return false;
        }
    
    }
    bool Delete_Course(Course* x){

        if (head == NULL) {
            cout << "No Enrolled Courses" << endl;
            return false;
        }
        SLLNode<Course> *curr = head;
        SLLNode<Course> *temp ;
        
        if (*curr->Dataaddress == *x){
            head=curr->next;
            delete curr;
            x->free_seat();
            Student*  studentturn = x->dequeue_from_waitlist();
            if (studentturn != NULL){
                studentturn->RegisterCourse(x);
            }
            return true;
        }
        while(curr->next != NULL && !(*curr->next->Dataaddress == *x)){
            curr = curr->next;
        }
        if (curr->next == NULL){return false;}else {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
             x->free_seat();
            Student*  studentturn = x->dequeue_from_waitlist();
            if (studentturn != NULL){
                studentturn->RegisterCourse(x);
            }
            return true;
        }
    }
    void deleteStudent(int id){
    if (head == NULL){
        cout << "There are no students" << endl;
        return;
    }
    bool Delete_Course_from_hash(Course* x){

        if (head == NULL) {
            return false;
        }
        SLLNode<Course> *curr = head;
        SLLNode<Course> *temp ;
        
        if (*curr->Dataaddress == *x){
            head=curr->next;
            delete curr;
            return true;
        }
        while(curr->next != NULL && !(*curr->next->Dataaddress == *x)){
            curr = curr->next;
        }
        if (curr->next == NULL){return false;}else {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return true;
        }
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
    Course* FindCourseByNumber(int x){
        int counter = 1;
        if (head == NULL)return NULL;
        SLLNode<Course> *curr = head;
        while(curr!=NULL && counter != x){
            curr=curr->next;
            counter++;
        }
        if (curr==NULL)return NULL;
        return curr->Dataaddress;
    }
    
    void swap(SLLNode<T>* curr, SLLNode<T>* innercurr){
        T *temp = curr->Dataaddress;
        (curr->Dataaddress) = (innercurr->Dataaddress);
        innercurr->Dataaddress = temp;
    }

    void selection_sort(){
        SLLNode<T>* minnode = head ;
        for (SLLNode<T>* curr = head ; curr!= NULL  ; curr = curr->next){
            SLLNode<T>* minnode = curr ; 
            for (SLLNode<T>* innercurr = curr  ;  innercurr!= NULL ; innercurr = innercurr->next){
                if (*(innercurr->Dataaddress) < *( minnode->Dataaddress) ){
                    minnode = innercurr;
                }
            }
            swap(curr, minnode);
        }
    }
};

#endif