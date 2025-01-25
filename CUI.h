#ifndef CUI_H
#define CUI_H
#include <chrono>
#include <conio.h>
#include <thread> 
#include <iostream>
#include "Course.h"
#include "University.h"
#include "windows.h"

using namespace std ;

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
    Sleep(1000);
    clear();
    First_Page();
}
void First_Page(){

 char choice;
    while (true) {

        printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
        printWhite("1. Login\n");
        printWhite("2. Register\n");
        printWhite("Please select an option: ");
        cin >> choice;
        switch (choice)
        {
        case '1':
            loginpage();
            break;
        case '2':
            registerpage();
            break;
        default:
            clear();
            break;
        }
    }


}
void loginpage(){
clear();
        printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
        string Email, Password;
        printWhite("Enter Student Email: ");
        cin >> Email;
        printWhite("Enter Student Password: ");
        cin >> Password;
        Student *x;
        if ((*MyUniversity).checkstudentdetails(Email,Password,x)) {
            printBlue("\nStudent login successful!\n");
            studentloggedin(x);
        } else {
            clear();
            printBlue("\nInvalid student credentials.\n");
        }
    
}
void registerpage(){
    clear();
    char choice;
    printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
    printWhite("1. Student Account\n");
    printWhite("2. Moderator Account\n");
    printWhite("Please select an option: ");
    cin >> choice;
    switch (choice)
    {
    case '1':
        studentregisterpage();
        break;
    case '2':
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
    printWhite("Enter Your First Name: ");
    cin >> fname;
        printWhite("Enter Your Last Name: ");
    cin >> lname;
    printWhite("Enter Your Phone: ");
    cin >> phone;
    while(phone.length() != 11 || phone[0] != '0' || phone[1] != '1'){
        cout << "e7trm nfsk " << endl;
        printWhite("Enter Your Phone: ");
        cin >> phone;
    }
        printWhite("Enter Your Address: ");
    cin >> address;
        printWhite("Enter Your Password: ");
    cin >> password;
    while(password.length() < 8 ){
        cout << "e7trm nfsk y7bb" << endl;
        printWhite("Enter Your Password: ");
        cin >> password;
    }
    Student newstudent(fname,lname,phone,address,password);
    (*MyUniversity).Add_To_Student_Record(&newstudent);
    clear();
    printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
    cout << "Student Added Successfully" << endl;
    cout << "Email : " << newstudent.Get_Email()<< endl;
    cout << "ID : " << newstudent.Get_ID() << endl;

}
void studentloggedin(Student*&student) {
    char choice;
    while (true) {
        clear();
        printBlue("\n--- NILE UNIVERSITY MANAGEMENT SYSTEM ---\n");
        printWhite("1. Enrolled Courses\n");
        printWhite("2. Transcript\n");
        printWhite("3. Personal Information\n");
        printWhite("4. Logout\n");
        printWhite("Please select an option: ");
        cin >> choice;

        switch (choice) {
            case '1': // Enrolled Courses
                clear();
                printBlue("\n--- ENROLLED COURSES ---\n");
                student->Display_Enrolled_Courses();
                printWhite("\nPress any key to continue...");
                getch();
                clear();
                printBlue("\n--- ENROLLED COURSES ---\n");
                        printWhite("1. Register A Course\n");
                        printWhite("2. Withdraw From A Course\n");
                        printWhite("3. Back\n");
                        printWhite("Please select an option: ");
                        cin >> choice;
                        if (choice == '3'){ //Back
                            break;
                        }
                        if (choice == '1'){//Register
                            clear();
                            printBlue("\n--- AVAILABLE COURSES ---\n");
                            (this->MyUniversity)->Display_All_Courses();
                            cin >> choice;
                            int realchoice1 = choice - '0';
                            if (realchoice1 > (this->MyUniversity)->Get_Number_Of_courses() || realchoice1 < 1){
                                printRed("Invalid Choice");
                                Sleep(1000);
                                break;
                            }else {
                                int realchoice = choice - '0';
                                Course *Temp = (this->MyUniversity)->FindCourseByNumber(realchoice);

                                if (Temp !=NULL){
                                    cout << Temp->Get_Name() << endl;
                                    Sleep(1000);
                                    if((student)->RegisterCourse(Temp)){
                                        printRed("Course Registered Successfully");
                                        Sleep(1000);
                                    }else {
                                        printRed("Unable To Register Course");
                                        Sleep(1000);
                                        
                                    }
                                
                                }break;
                            }
                        }
                        if (choice == '2'){//Withdraw
                            clear();
                            printBlue("\n--- ENROLLED COURSES ---\n");
                            student->Display_Enrolled_Courses();
                            cin >> choice;
                            int realchoice1 = choice - '0';
                            if (realchoice1 > (student)->Get_Number_Of_Enrolled_Courses() || realchoice1 < 1){
                                printRed("Invalid Choice");
                                Sleep(1000);
                                break;
                            }else {
                                int realchoice = choice - '0';
                                Course *Temp = student->FindCourseByNumber(realchoice);
                                if (Temp != NULL){
                                    if ((student)->WithdrawCourse(Temp)){
                                    printRed("Course Withdrawn Successfully");
                                    cout << endl;
                                    Sleep(1000);
                                    break;
                                    }
                                }else{
                                    printRed("Couldn't Withdraw Course");
                                    cout << endl;
                                    Sleep(1000);
                                    break;   
                                    }
                                }
                            }else {printRed("Invalid Choice");Sleep(1000); break;}

            case '2': // Transcript
                clear();
                printBlue("\n--- TRANSCRIPT ---\n");
               // student->DisplayTranscript(); 
                printWhite("\nPress any key to continue...");
                getch();

                break;

            case '3': // Personal Information
                clear();
                printBlue("\n--- PERSONAL INFORMATION ---\n");
               // student->DisplayPersonalInfo(); 
                break;

            case '4': // Logout
                clear();
                printBlue("\nLogging out...\n");
                Sleep(1000); // 34an yban sre3 w kda
                clear();
                return; // yrg3 main menu

            default:
                clear();
                printRed("Invalid option. Please try again.\n");
                Sleep(1000);
                break;
        }
    }
}

};

#endif