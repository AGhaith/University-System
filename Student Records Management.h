#ifndef STUDENT_RECORD_MANGMENT_H
#define STUDENT_RECORD_MANGMENT_H
#define SLL_H

#include <iostream>
#include "Course.h" // Ensure Course.h is included before using Course methods
#include "Student.h" // Ensure Student.h is included before using Student methods
using namespace std;

class Student;
class Course;

template<class T>
class SLLNode {
public:
    T *Data;
    SLLNode* next = NULL;

    SLLNode(T *Data) {
        this->Data = Data;
    }
};

template <class T>
class SLL {
private:
    SLLNode<T>* head = NULL;
public:
    //overriding bool operator in students and courses so that when comparing student to student the comparison is done by id
    bool Find(T *x){
        SLLNode<T>*curr = head;
        while(curr!=NULL){
            if (curr->Data->get_name() == *x->get_name()){
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
    void insert(T *mydata){

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
    void Display_Courses() {
        int counter = 1;
        if (head == NULL) {
            cout << "No Enrolled Courses" << endl;
            return;
        }
        SLLNode<T> *curr = head;
        while (curr != NULL) {
            cout << counter << '.' << curr->Data->get_name() << endl;
            counter++;
            curr = curr->next;
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
            cout << "Couldn't Find Email" << endl;
            return false;
        }else {
            if(curr->Data.Get_Password() == password){
            x=&(curr->Data);
            return true;
            }
            return false;
        }
    
    }
    bool Delete_Course(T *x) {
        if (head == NULL) {
            cout << "No Enrolled Courses" << endl;
            return false;
        }
        SLLNode<T> *curr = head;
        SLLNode<T> *temp;

        if (curr->Data == *x) {
            head = curr->next;
            delete curr;
            return true;
        }
        while (curr->next != NULL && !(curr->next->Data == *x)) {
            curr = curr->next;
        }
        if (curr == NULL) {
            return false;
        } else {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return true;
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
    T FindCourseByNumber(int x) {
        int counter = 1;
        T emptyCourse("EMPTY", "NULL", 0, 0);
        if (head == NULL) return emptyCourse;
        SLLNode<T> *curr = head;
        while (curr != NULL && counter != x) {
            curr = curr->next;
            counter++;
        }
        if (curr == NULL) return emptyCourse;
        return *(curr->Data);
    }
};
class Student_Records_Management{

    private:

    SLL<Student> SLL_Students ; 

    public:

    void Add_student(Student *mystudent){
        SLL_Students.insert(mystudent) ; 
    }

    void Add_Course(Student *mystudent , Course *x){
        mystudent->add_to_finished_courses(x);
        cout << "Course " << x->get_name() << " Successfully Added to " << mystudent->Get_First_Name() << " " << mystudent->Get_Last_Name() << "'s " << "Transcript" << endl;
    }
    void Delete_Student(int ID){
        SLL_Students.deleteStudent(ID) ; 
    }

    void display(){
        SLL_Students.Display_Student_Records();
    }

    bool check(string email,string password,Student *&x){
        return SLL_Students.checkuserinfo(email,password,x);
    }
};

#endif