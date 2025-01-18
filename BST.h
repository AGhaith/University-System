#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;


class BSTNode {
public:
    BSTNode* right = NULL;
    BSTNode* left = NULL;
    Course Content;
    BSTNode(Course Content) {
        this->Content = Content;
    }

};


#endif // BST_H
