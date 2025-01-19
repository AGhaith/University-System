#ifndef CUI_H
#define CUI_H
#include <chrono>
#include <thread> 
#include <iostream>
#include "University.h"
#include "windows.h"
#include "Student.h"
using namespace std ;
#define RESET "\033[0m"
void clear() {
    system("CLS"); 
}
void printBlue(string text) {
    
    const string BRIGHT_BLUE = "\033[94m";
    std::cout << BRIGHT_BLUE << text << RESET;
}

void printWhite(string text) {
    const string WHITE = "\033[37m";
    std::cout << WHITE << text << RESET;
}
class CUI{
private:
university *MyUniversity;
public:
CUI(university myuni){
(this->MyUniversity) = &myuni;
}
void welcome(){
    clear();
printBlue("*********************************************\n");
    printWhite("                   WELCOME\n");
    printWhite("      NILE UNIVERSITY MANAGEMENT SYSTEM\n");
    printBlue("*********************************************\n");
    Sleep(2500);
    clear();
    First_Page();
}
void First_Page(){
 int choice;
    while (true) {
        printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
        printWhite("1. Login\n");
        printWhite("2. Register\n");
        printWhite("Please select an option: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            loginpage();
            break;
        case 2:
            registerpage();
            break;
        default:
            break;
        }
    }

}
void loginpage(){
clear();
        printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
        string Email, Password;
        printWhite("Enter Student Email: ");
        std::cin >> Email;
        printWhite("Enter Student Password: ");
        std::cin >> Password;

        if ((*MyUniversity).checkstudentdetails(Email,Password)) {
            printBlue("\nStudent login successful!\n");
        } else {
            clear();
            printBlue("\nInvalid student credentials.\n");
        }
    
}
void registerpage(){
    clear();
    int choice;
    printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
    printWhite("1. Student Account\n");
    printWhite("2. Moderator Account\n");
    printWhite("Please select an option: ");
    cin >> choice;
    switch (choice)
    {
    case 1:
        studentregisterpage();
        break;
    case 2:
        registerpage();
        break;
    default:
        break;
    }

}
void studentregisterpage(){
    clear();
    printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
    string fname,lname,address,phone,password;
    printWhite("Enter Student First Name: ");
    cin >> fname;
        printWhite("Enter Your Last Name: ");
    cin >> lname;
    printWhite("Enter Your Phone: ");
    cin >> phone;
    while(phone.length() < 11 || phone[0] != '0' || phone[1] != '1'){
        cout << "e7trm nfsk " << endl;
        printWhite("Enter Your Phone: ");
        cin >> phone;
    }
        printWhite("Enter Your Address: ");
    cin >> address;
        printWhite("Enter Your Password: ");
    cin >> password;
    Student newstudent(fname,lname,phone,address,password);
    (*MyUniversity).Add_To_Student_Record(newstudent);
    clear();
    printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
    cout << "Student Added Successfully" << endl;
    cout << "Email : " << newstudent.Get_Email()<< endl;
    cout << "ID : " << newstudent.Get_ID() << endl;

}

};

#endif