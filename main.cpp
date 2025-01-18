#include<iostream>
#include "University.h"
/* 
        University Class :
            Student Records Managment Class Using Single Linked List(SLL):

                Add_To_Student_Record(Student) to add a new student
                as for the id we dont need to add it as a parameter because it is calculated and assigned automatically to each student
                Delete_Student_Record(id) to search for a student and delete them using their id
                Display_Student_Records() to print all student details
                Add_Course_To_Student()
                Drop_Course_For_Student()

            Course Records Managment Class Using Binary Search Tree(BST):

                Add_New_Course()add a new course 
                
                


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
nileuniversity.Add_To_Student_Record(s1);
nileuniversity.Add_To_Student_Record(s2);
nileuniversity.Add_To_Student_Record(s3);
// Printing the record
nileuniversity.display_Student_Records();
// Deleting From the record
nileuniversity.Delete_Student_Record(1);
// Printing Again
nileuniversity.display_Student_Records();


}