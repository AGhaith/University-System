#include<iostream>
#include"course.h"
#include"Course Registration.h"
using namespace std;
class Course{
private:
string CourseID;
string CourseName,CourseInstructor;
int CourseCredits;
public:
Course(string ID="",string name="",string instructor="",int credits=0){
CourseID=ID;
CourseName=name;
CourseInstructor=instructor;
CourseCredits=credits;
}
string get_id(){
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
template <class T>
class BSTNode{
private:
public:

};
int main(){


}