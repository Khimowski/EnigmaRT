//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#include <iostream>
#include "password.h"
#include "data.h"
#include "menu.h"
#include "rotor.h"

#define OK 1
#define ERROR -1
#define NOTFOUND 0
#define TRUE 1
#define FALSE 0

using namespace std;

int main() {
    system("chcp 65001");

    ListInit(head);
    INIT_ENIGMA();
    while(TRUE) {
        MAIN_MENU();
        int choice;
        cin>>choice;
        if(choice == 1) {
            while(TRUE) {
                PWD_MENU();
                cin>>choice;
                if(choice == 1) {
                    OPE_PWD_ADD();
                }
                else if(choice == 2) {
                    OPE_PWD_SEE();
                }
                else if(choice == 3) {
                    OPE_PWD_DRT();
                }
                else if(choice == 4) {
                    OPE_PWD_DEL();
                }
                else if(choice == 5) {
                    break;
                }
                else {
                    NOTFD();
                }
            }
        }
        else if(choice == 2) {
            while(TRUE) {
                ENIGMA_MENU();
                cin>>choice;
                if(choice == 1) {
                    NEW_ENIGMA();
                }
                else if(choice == 4) {
                    break;
                }
                else {
                    NOTFD();
                }
            }
        }
        // else if(choice == 999) {
        //     OPE_TEST();
        // }
        else if(choice == 3) {
            break;
        }
        else {
            NOTFD();
        }

    }
    return 0;
}
