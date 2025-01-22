
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std ;
long long Student_ID_Counter=250000000;
int Course_ID_Counter = 1;

#define RESET "\033[0m"
void clear() {
    system("CLS"); 
}
void printBlue(string text) {
    
    const string BRIGHT_BLUE = "\033[94m";
    cout << BRIGHT_BLUE << text << RESET;
}

void printWhite(string text) {
    const string WHITE = "\033[37m";
    cout << WHITE << text << RESET;
}
void printRed(string text) {
    const string RED = "\033[1;31m";
    cout << RED << text << RESET;
}
string lower(const string str) {
    string result = str;
    for (char &c : result) {
        c = tolower(c);
    }
     return result;
}



