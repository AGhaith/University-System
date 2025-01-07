
#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
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
    BSTNode(BSTNode<T>* right = NULL, BSTNode<T>* left = NULL, T Content) {
        this->right = right;
        this->left = left;
        this->Content = Content;
    }
};
template <class T>
class CourseRecordManagment {
public:
    BSTNode<T> *root = NULL;
    void addCourse(Course x) {
        if (root == NULL){
            root = new BSTNode(x);
        }else{
            
        }
    }

    void dropCourse() {

    }
};

#endif // SYSTEMHEADER_H
