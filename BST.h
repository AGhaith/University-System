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
    Course Content;
    BSTNode(Course Content) {
        this->Content = Content;
    }

};


#endif // BST_H
