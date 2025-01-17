#ifndef COURSE_RECORDS_MANAGEMENT_H
#define COURSE_RECORDS_MANAGEMENT_H

#include <iostream>
#include <string>
#include "Course.h"
#include "BST.h"
using namespace std;

template <class T>
class CourseRecordManagment {
public:
    BSTNode<T> *root = NULL;
    void addCourse(Course x) {
        root =insertNode(root,x);
    }
    BSTNode<T>* insertNode(BSTNode<T> *&root, Course val){
        if (root == NULL){
            root = new BSTNode<T>(val);
            return root;
        }
        if (val > root->value){
            root->right = insertNode(root->right,val);
        }
        else {
            root->left = insertNode(root->left,val);

        }
        return root;
    }
    void dropCourse(string x) {
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
    bool search(BSTNode<T> *root ,string x){
        if (root == NULL){
            return false;
        }
        if (root->Content.CourseID == x){
            return true;
        }
        if (root->Content.CourseID > x){
            return search(root->left,x);
        }
        if (root->Content.CourseID < x){
            return search(root->right,x);
        }
    }
};

#endif // COURSE_RECORDS_MANAGEMENT_H
