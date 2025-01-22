#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <fstream>
#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
#include "SLL.h"
#include"DLL.h"
#include "Course Registration.h"
#include "Course Records Management.h"
#include "Student Records Management.h"

using namespace std;

class university{

private:
Student_Records_Management StudentRecords;
Course_Records_Managment CourseRecords;
//DLL<Course> Course_Enrollment_history ;
int NumberOfCourses = 0;

public:
    int Get_Number_Of_courses(){
        return NumberOfCourses;
    }
    void display_Student_Records(){
        StudentRecords.display();
    }
    void Add_To_Student_Record(Student a){
        StudentRecords.Add_student(a);
    }
    void Add_To_Student_Record(Student a,Course x){
        StudentRecords.Add_Course(a,x);
    }
    void Delete_Student_Record(int id){
        StudentRecords.Delete_Student(id);

    }
    void Add_New_Course(Course A){
        NumberOfCourses++;
        CourseRecords.addCourse(A);
    }
    void Drop_Course(int id){
        NumberOfCourses--;
        CourseRecords.dropCourse(id);

    }
    void Display_All_Courses(){
        CourseRecords.Display();
    }
    Course FindCourseByNumber(int x){
        return CourseRecords.FindCourseByNumber(x);
    }
    bool checkstudentdetails(string email,string password,Student *&x){
        return StudentRecords.check(email,password,x);
    }
    // void add_course_enrollment_history(Course course_to_enroll){
    //     Course_Enrollment_history.add(course_to_enroll) ; 
    // }
    // void view_enrollment_history(){
    //     Course_Enrollment_history.view() ; 
    // }
    /*
    bool checkmoderatordetails(string email,string password){
        return ModeratorRecords.check(email,password);
    }
    */
    
};


#endif // UNIVERSITY_H