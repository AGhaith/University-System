#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;
int Course_ID_Counter = 1;
class Course {
private:
    int CourseID, CourseCredits;
    string CourseName, CourseInstructor;

public:
    Course(string name = "", string instructor = "", int credits = 0) {
        CourseID = Course_ID_Counter;
        Course_ID_Counter++;
        CourseName = name;
        CourseInstructor = instructor;
        CourseCredits = credits;
    }

    int get_id() {
        return CourseID;
    }

    string get_name() {
        return CourseName;
    }

    string get_instructor() {
        return CourseInstructor;
    }

    int get_credits() {
        return CourseCredits;
    }
};


#endif // COURSE_H
