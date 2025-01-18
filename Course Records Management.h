#ifndef COURSE_RECORDS_MANAGEMENT_H
#define COURSE_RECORDS_MANAGEMENT_H

#include <iostream>
#include <string>
#include "Course.h"
#include "BST.h"
using namespace std;


class Course_Records_Managment {
public:
    BSTNode *root = NULL;
    void addCourse(Course x) {
        root = insertNode(root,x);
    }
    BSTNode* insertNode(BSTNode *&root, Course val){
        if (root == NULL){
            root = new BSTNode(val);
            return root;
        }
        if (val.get_id() > root->Content.get_id()){
            root->right = insertNode(root->right,val);
        }
        else {
            root->left = insertNode(root->left,val);

        }
        return root;
    }
    void dropCourse(int x) {
        //remove(x);
    }

   /* void remove(string x){
        if (root == NULL){
            return false;
        }
        if (root->Content.CourseID == x){
            //delete
        }
        if (root->Content.CourseID > x){
            return search(root->left,x);
        }
        if (root->Content.CourseID < x){
            return search(root->right,x);
        } 
    }
    */
    bool search(BSTNode *root ,int x){
        if (root == NULL){
            return false;
        }
        if (root->Content.get_id() == x){
            return true;
        }
        if (root->Content.get_id() > x){
            return search(root->left,x);
        }
        if (root->Content.get_id() < x){
            return search(root->right,x);
        }
    }
};

#endif // COURSE_RECORDS_MANAGEMENT_H
