#include <iostream>
#include <unordered_map>
#include "course.h"
#include "SLL.h"
using namespace std;
unordered_map<int,SLL<Course>> FinishedCoursesHashmap;
int hashing(Course mycourse){
    int final = 0;
    string a = mycourse.Get_Name();
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
bool searchWithHashing(Course x){
    int index = hashing(x);
    return FinishedCoursesHashmap[index].Find(x);
}
int main(){
Course c1("MATH101","NULL",4);
Course c2("MATH102","NULL",4);
Course c3("MATH101","NULL",4);


cout << hashing(c1) << endl;
cout << hashing(c2) << endl;
FinishedCoursesHashmap[hashing(c1)].insert(c1);
FinishedCoursesHashmap[hashing(c2)].insert(c2);
//FinishedCoursesHashmap[hashing(c3)].insert(c3);
FinishedCoursesHashmap[hashing(c1)].Display_Courses();
FinishedCoursesHashmap[hashing(c2)].Display_Courses();
cout << searchWithHashing(c1) << endl;
cout << searchWithHashing(c2) << endl;
cout << searchWithHashing(c3) << endl;



}