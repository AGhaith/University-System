#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "course.h" // Include full definition of Course
#include "Person.h"
#include "SLL.h"    // Include full definition of SLL
using namespace std ;



class Student:public Person{

    private:

    int Student_id; 
    SLL<Course> RegisteredCourses;
    SLL<Course> Waitlist;
    unordered_map<int,SLL<Course>> FinishedCoursesHashmap;
    string suffix = "@nu.edu.eg";
    string dot = ".";
    int NumberOfEnrolledCourses=0;
    public:
    Student(){

    }
    Student(string first_name, string last_name , string Phone ,string Address , string Password){
        this->Student_id = Student_ID_Counter ;
        Student_ID_Counter++; 
        this->First_name = first_name ; 
        this->Last_name = last_name ; 
        this->Email = first_name[0]+dot+last_name+to_string((Student_id/10)%10)+to_string(Student_id%10)+suffix;
        this->Phone = Phone ;
        this->Address = Address ; 
        this->Password = Password ;
    }
    
    int Get_ID(){
        return Student_id ; 
    }
    int Get_Number_Of_Enrolled_Courses(){
        return NumberOfEnrolledCourses;
    }
    Course FindCourseByNumber(int Course_To_Find){
        return RegisteredCourses.FindCourseByNumber(Course_To_Find);
    }


    bool check_Prerequisites(Course x ){
        
        Stack<Course> copy_prerq = x.getcopy() ; 

        while (!copy_prerq.is_empty()){

            Course curr_course = copy_prerq.get_top();

            if ((this)->searchWithHashing(x)){
                copy_prerq.Pop();
            }
            else{
                cout <<"///" << endl ; 
                return false;
            }
        }

        if(!copy_prerq.is_empty()){
            return false ; // lesa feha courses makhlshasah
        }
        return true;
    }


    bool RegisterCourse(Course Course_To_Register){
        // check in hash
        if (RegisteredCourses.Find(Course_To_Register))
        {
            Course_To_Register.showrequiredcourses();
            printRed("student already registered");
            cout << endl; 
            return false ;
        }
        //check in stack of prerquistes

        if (!(this->check_Prerequisites(Course_To_Register))){ 

                printRed("Student didn't finish all required courses");
                cout << endl; 
                return false ;
            } 
        
        RegisteredCourses.insert(Course_To_Register);
        NumberOfEnrolledCourses++;
        cout <<"student succefully enrolled " << endl ;
        return true ;
        
    }
    bool WithdrawCourse(Course Course_To_Withdraw){
        bool temp = RegisteredCourses.Delete_Course(Course_To_Withdraw);
        if (temp){
            NumberOfEnrolledCourses--;
            return temp;
        }
        else return temp;
        
    }
    void Display_Enrolled_Courses(){
        RegisteredCourses.Display_Courses();
    }
    int hashing(Course mycourse){
        int final = 0;
        string a = mycourse.get_name();
        for(int i = 0 ; i < a.length() ; i++){
            int temp = a[i];
            if (i-1==a.length()){
                final = final + temp*2;
            }else {
                final+=a[i];
            }
        }
        return final;

    }
    void Add_To_Finshed_courses(Course mycourse){

        FinishedCoursesHashmap[hashing(mycourse)].insert(mycourse);

    }
    // Look up courses with hashtable
    bool searchWithHashing(Course x){
        int index = hashing(x);
        return FinishedCoursesHashmap[index].Find(x);
    }
    /*void display_enrolled_courses(){

        finished_courses.display() ; 
    }*/
    
    bool operator==(Student other) const {
        return this->Student_id == other.Student_id ;
    }

};

#endif
