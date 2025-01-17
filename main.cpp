#include<iostream>
#include "University.h"
/* 
        University Class :
            Student Records Managment Class Using Single Linked List(SLL):

                AddToStudentRecord(Student) to add a new student
                as for the id we dont need to add it as a parameter because it is calculated and assigned automatically to each student
                DeleteStudentRecord(id) to search for a student and delete them using their id
                displayStudentRecords() to print all student details

            Course Records Managment Class Using Binary Search Tree(BST):
                addCourse()
                drop


*/
#include "Student.h"
/* 
    Student Class:
    to create students with attributes 
    (string name , string Email , string Phone ,string Address , string Password)

*/
using namespace std;
int main(){
university nileuniversity;
// Creating Students
Student s1("Ahmed Ghaith","A.Wesam2300@nu.edu.eg","01021565688","8th District","Password@1");
Student s2("Omar Sholkamy","A.Wesam2300@nu.edu.eg","01021565688","8th District","Password@2");
Student s3("Yousef Amir","A.Wesam2300@nu.edu.eg","01021565688","8th District","Password@3");
// Addint to the record
nileuniversity.AddToStudentRecord(s1);
nileuniversity.AddToStudentRecord(s2);
nileuniversity.AddToStudentRecord(s3);
// Printing the record
nileuniversity.displayStudentRecords();
// Deleting From the record
nileuniversity.DeleteStudentRecord(1);
// Printing Again
nileuniversity.displayStudentRecords();


}