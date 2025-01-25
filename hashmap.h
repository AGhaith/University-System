#ifndef HASHMASP_H
#define HASHMASP_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "Course.h"

using namespace std;


class Hashmap{
    private:

    unordered_map<int,SLL<Course>> hashmap;

    public:

    int hashing(Course *mycourse){
        int final = 0;
        string a = mycourse->get_name();
        for(int i = 0 ; i < a.length() ; i++){
            int temp = a[i];
            if (i-1==a.length()){
                final = final + temp*2;
            }else {
                final+=a[i];
            }
        }
        return final;

    }

    void Add_to_hash(Course *mycourse){

        hashmap[hashing(mycourse)].insert(mycourse);

    }
    
// Look up courses with hashtable
    bool searchWithHashing(Course *x){
        int index = hashing(x);
        return hashmap[index].Find(x);
    }

};






#endif