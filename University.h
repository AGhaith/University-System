#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>
#include "Course.h"
#include "Course Registration.h"
#include "Course Records Management.h"
#include "Student Records Management.h"

using namespace std;

class university{

private:
Student_Records_Management StudentRecords;
Course_Records_Managment CourseRecords;

public:
    void display_Student_Records(){
        StudentRecords.display();
    }
    void Add_To_Student_Record(Student a){
        StudentRecords.Add_student(a);
    }
    void Delete_Student_Record(int id){
        StudentRecords.Delete_Student(id);

    }
};


#endif // UNIVERSITY_H