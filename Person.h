#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std ;

class Person{

    protected:
    string First_name  ;
    string Last_name;
    string Email  ; 
    string Phone  ; 
    string Address  ; 
    string Password  ; 
    public:
    string Get_First_Name(){
        return First_name ; 
    }
    string Get_Last_Name(){
        return Last_name ; 
    }
    string Get_Email(){
        return Email ; 
    }
    string Get_Phone(){
        return Phone ; 
    }
    string Get_Address(){
        return Address ; 
    }
    string Get_Password(){
        return Password ; 
    }  
Person() : First_name(""), Last_name(""), Email(""), Phone(""), Address(""), Password("") {}
virtual ~Person() {}

    

};

#endif
