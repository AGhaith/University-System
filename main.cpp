#include"windows.h"
#include<iostream>
/* 
    Student Class:
    to create Students with attributes 
    (string name , string Email , string Phone ,string Address , string Password)
    as for the id we dont need to add it as a parameter because it is calculated and assigned automatically to each Student

*/
#include "Course.h"
/* 
    Course Class:
    to create Courses with attributes 
    (string name , string instructor , int credits )
    as for the id we dont need to add it as a parameter because it is calculated and assigned automatically to each Course

*/
#include "University.h"

/* 
    University Class :
        Student Records Managment Class Using Single Linked List(SLL):

            Add_To_Student_Record(Student) to add a new student to the record
            Delete_Student_Record(id) to search for a student and delete them using their id
            Display_Student_Records() to print all student details
            Add_Course_To_Student()
            Drop_Course_For_Student()

        Course Records Managment Class Using Binary Search Tree(BST):

            Add_New_Course() -> Add a new course To The University
            Drop_Course() -> Remove That Course From University
*/
#include"CUI.h"
#include <windows.h>
using namespace std;

int main(){
university nileuniversity;
// Creating Courses 

Course c1("MATH101","NULL",4,1);
Course c2("MATH102","NULL",4,2);
Course c3("MATH103","NULL",4,3);
Course c4("CSCI207","NULL",4,4);
Course c5("CSCI112","NULL",4,5);

// Adding them to the record

nileuniversity.Add_New_Course(&c1);
nileuniversity.Add_New_Course(&c2);
nileuniversity.Add_New_Course(&c3);
nileuniversity.Add_New_Course(&c4);
nileuniversity.Add_New_Course(&c5);


// Creating Students 

Student s1("Ahmed","Ghaith","01021565688","8th District","Password@1");

//A.Ghaith00@nu.edu.eg
//Password@1

Student s2("Omar","Sholkamy","01021565688","8th District","Password@2");
Student s3("Yousef","Amir","01021565688","8th District","Password@3");

// lw hancheck selection sort 3la arkam so8yra :)
// s1.set_ID(3);
// s2.set_ID(4);
// s3.set_ID(1);

// Adding them to the record

nileuniversity.Add_To_Student_Record(&s1);
nileuniversity.Add_To_Student_Record(&s2);
nileuniversity.Add_To_Student_Record(&s3);

c2.Add_To_Prerequisites(&c1);
c3.Add_To_Prerequisites(&c2);

CUI commandlineinterface(nileuniversity);
commandlineinterface.welcome();

// // Printing the record
// nileuniversity.display_Student_Records();
// // Deleting From the record
// nileuniversity.Delete_Student_Record(2);
// // Printing Again
// nileuniversity.display_Student_Records();
// // Creating Courses (string name , string instructor , int credits )
// Course c1("MATH101","NULL",4);
// nileuniversity.Add_New_Course(c1);
// nileuniversity.Drop_Course(1);
// nileuniversity.Add_To_Student_Record(s1,c1);
}