
#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

template <class T>
class BSTNode {
public:
    BSTNode<T>* right = NULL;
    BSTNode<T>* left = NULL;
    T Content;
    BSTNode(T Content) {
        this->Content = Content;
    }

};
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
    void dropCourse(Course X) {
        remove(x);
    }
    remove(Course x){
        if (search(x) != NULL) {



        }else {
            cout << "Courses doesn't exist";
            return;
        }

    }
    search(Course x){

    }
};

#endif // BST_H
