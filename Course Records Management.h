#ifndef COURSE_RECORDS_MANAGEMENT_H
#define COURSE_RECORDS_MANAGEMENT_H

#include <cstddef>
#include <iostream>
#include <string>
#include "Course.h"
#include "BST.h"
using namespace std;


class Course_Records_Managment {
public:
    BSTNode *root = NULL;
    void addCourse(Course x) {
        
        cout << "Inseted at " << insertNode(root,x) << endl;
        cout << "-------------------------------------------------------------" << endl;

    }
 
    void Display(){
        int counter = 1;
        Displaypreorder(root,counter);

    }
    void Displaypreorder(BSTNode *&root,int counter){ //HLR
    
        if (root == NULL){
            return;
        }
        cout << counter << '.' << root->Content.get_name() << endl;
        counter++;
        Displaypreorder(root->left,counter);
        Displaypreorder(root->right,counter);
    }
    Course FindCourseByNumber(int x) {
    int counter = 0; 
    return Findpreorder(root, counter, x);
}

Course Findpreorder(BSTNode* root, int& counter, int key) { // HLR 
    if (root == nullptr) {
        Course emptyCourse("EMPTY", "NULL", 0); 
        return emptyCourse;
    }

    counter++; 
    if (counter == key) {
        return root->Content;
    }

    // Traverse the left subtree
    Course leftResult = Findpreorder(root->left, counter, key);
    if (leftResult.get_name() != "EMPTY") { 
        return leftResult; 
    }

    // Traverse the right subtree
    Course rightResult = Findpreorder(root->right, counter, key);
    if (rightResult.get_name() != "EMPTY") {
        return rightResult; 
    }

    Course emptyCourse("EMPTY", "NULL", 0);
    return emptyCourse;
}
    BSTNode* insertNode(BSTNode *&root, Course val){
        if (root == NULL){
            root = new BSTNode(val);
            return root;
        }
        if (val.get_ID() > root->Content.get_ID()){
            root->right = insertNode(root->right,val);
        }
        else {
            root->left = insertNode(root->left,val);

        }
        return root;
    }
    void dropCourse(int x) {
        if (search(root,x)){
            remove(root,x);
            cout << "Object Deleted Successfully" << endl;
            cout << "-------------------------------------------------------------" << endl;
            return;

        }else {
            return;
        }
    }
    Course minValue(BSTNode *root){
        if (root->left == NULL)
            return root->Content;
        return minValue(root->left);
    }
    BSTNode* remove(BSTNode* root, int x){
        if (root == NULL){
            return root;
        }
        if (root->Content.get_ID() > x){
            root->left = remove(root->left,x);
        }
        if (root->Content.get_ID() < x){
            root->right = remove(root->right,x);
        } 
        if (root->Content.get_ID() == x){
            if (root->left == NULL && root->right == NULL){
                return NULL;
            }
            if(root->left == NULL){
                return root->right;
            }
            if(root->right == NULL){
                return root->left;
            }
            Course n = minValue(root);
            root->right = remove(root->right,n.get_ID());
            root->Content = n;
        }
        return root;
    }
    
    bool search(BSTNode *root ,int x){
        if (root == NULL){
            cout << "Object Doesn't Exist" << endl;
            return false;
        }
        if (root->Content.get_ID() == x){
            cout << "Object Found" << endl;
            cout << "Deleting..." << endl;
            return true;
        }
        if (root->Content.get_ID() > x){
            return search(root->left,x);
        }
        if (root->Content.get_ID() < x){
            return search(root->right,x);
        }
        return false;
    }

};

#endif // COURSE_RECORDS_MANAGEMENT_H
