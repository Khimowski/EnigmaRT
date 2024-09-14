//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#include <iostream>
#include "password.h"
#include "data.h"
#include "menu.h"

#define OK 1
#define ERROR -1
#define NOTFOUND 0
#define TRUE 1
#define FALSE 0

using namespace std;

class rotor {
    public:
    int number;
    int code[8];
};

int main() {
    system("chcp 65001");

    ListInit(head);
    while(TRUE) {
        MENU1();
        int choice;
        cin>>choice;
        if(choice == 1) {
            OPE_ADD();
        }
        else if(choice == 2) {
            OPE_SEE();
        }
        else if(choice == 3) {
            OPE_DRT();
        }
        else if(choice == 4) {
            OPE_DEL();
        }
        else if(choice == 5) {
            break;
        }
        // else if(choice == 999) {
        //     OPE_TEST();
        // }
        else {
            OPE_NFD();
        }

    }
    return 0;
}
