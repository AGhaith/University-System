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

public:
    void displayStudentRecords(){
        StudentRecords.display();
    }
    void AddToStudentRecord(Student a){
        StudentRecords.Add_student(a);
    }
    void DeleteStudentRecord(int id){
        StudentRecords.Delete_Student(id);

    }
};


#endif // UNIVERSITY_H