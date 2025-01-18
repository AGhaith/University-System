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
        
        cout << "Inseted at " << insertNode(root,x) << endl;
        cout << "-------------------------------------------------------------" << endl;

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
    }
};

#endif // COURSE_RECORDS_MANAGEMENT_H
