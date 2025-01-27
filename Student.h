
#include <iostream>
#include <unordered_map>
#include <string>
#include "Course.h"
#include "Person.h"
#include "SLL.h"
#include "DLL.h"
using namespace std ;
class Course;


class Student:public Person{

    private:

    int Student_id; 
    SLL<Course> RegisteredCourses;
    SLL<Course> Waitlist;
    DLL<Course> Course_Enrollment_History ; 
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
    void set_ID(int id){
        Student_id = id ; 
    }
    Course *FindCourseByNumber(int Course_To_Find){
        return RegisteredCourses.FindCourseByNumber(Course_To_Find);
    }

    bool RegisterCourse(Course *Course_To_Register){
        // check in hash
        if ( RegisteredCourses.Findinaddress(Course_To_Register)) 
        {
            printRed("You Are Already Registered");
            return false ;
        }
        //check in stack of prerquistes
        if (!Course_To_Register->check_seats()){
            Course_To_Register->add_to_waitlist(this);
            printRed("Unfortunatly No Seats Are available, you have been added to the waitlist");
            printRed("your number is ");
            cout << Course_To_Register->How_Many();
            return false;
        }
        if (!(this->check_Prerequisites(*Course_To_Register))){ 
            printRed("Student didn't finish all required courses");
            return false ;
        } 

        //If student meets all requiremnents
        RegisteredCourses.insert_with_pointer(Course_To_Register);
        NumberOfEnrolledCourses++;
        Course_Enrollment_History.add(Course_To_Register);
        Course_To_Register->take_seat();
        this->Add_To_Finshed_courses(Course_To_Register);
        cout <<"student succefully enrolled " << endl ;
        return true ;
    }
    bool check_Prerequisites(Course x){
        
        Stack<Course> Prerequisites = x.Get_Copy_Of_Prerequisite_Stack();
        if (Prerequisites.is_empty()) {
            cout << "Prerequisite Stack Is Empty" << endl;
            Sleep(1000);
            return true;
        }
        int counter = 1;
        while (!Prerequisites.is_empty()) {
                cout << "Checking prerequisite Number "  << counter++ << endl;
                Course *curr_course = Prerequisites.Pop(); 
                if(curr_course != NULL){
                    cout << "Prerequiste Found !!!" << endl;
                    //cout << "Prerequisite : " << curr_course->Get_Name() << endl;
                    //Sleep(1000); 
                    if (!((this)->searchWithHashing(curr_course))) {
                        cout << "You Don't seem to have finished the required courses" << endl;  
                        return false; 
                    }
                }else return true;
            }
        return true;
    }
    bool WithdrawCourse(Course* Course_To_Withdraw){
        bool temp = this->RegisteredCourses.Delete_Course(Course_To_Withdraw);
        if (temp){
            NumberOfEnrolledCourses--;
            return temp;
        }
        else return temp;
        
    }
    void Display_Enrolled_Courses(){
        RegisteredCourses.Display_Courses();
    }
    int hashing(Course *mycourse){
        int final = 0;
        string a = mycourse->Get_Name();
        for(int i = 0 ; i < a.length() ; i++){
            int temp = a[i];
            if (i-1==a.length()){
                final = final + temp*2;
            }else {
                final+=temp;
            }
        }
        return final;

    }
    void Add_To_Finshed_courses(Course *mycourse){

        FinishedCoursesHashmap[hashing(mycourse)].insert_with_pointer(mycourse);

    }
    // Look up courses with hashtable
    bool searchWithHashing(Course *x){
        cout << "Check 1 " << endl
        int index = hashing(x);
        cout << "Check 2 " << endl;
        return FinishedCoursesHashmap[index].Findinaddress(x);
    }
    /*void display_enrolled_courses(){

        finished_courses.display() ; 
    }*/
    void print_student_info(){
        Student* curr = this;
        if (curr != NULL){
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << curr->Get_ID() << "  ||  " << curr->Get_First_Name() << " " << curr->Get_Last_Name() << "  ||  " << curr->Get_Email() << "  ||  " << curr->Get_Phone() << "  ||  " << curr->Get_Address() << "  ||  " << curr->Get_Password() << endl ;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        }
    }
    void DisplayTranscript(){
        Course_Enrollment_History.view();
    }
    bool operator==(Student other) const {
        return this->Student_id == other.Student_id ;
    }
    bool operator<(Student &other) const {
        return this->Student_id <= other.Student_id ;
    }  
};
