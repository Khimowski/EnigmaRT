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

int main() {
    system("chcp 65001");

    ListInit(head);
    ENIGMA_INIT();
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
                    OPE_ENIGMA_ADD();
                }
                else if(choice == 2) {
                    OPE_ENIGMA_PRT();
                }
                else if(choice == 3) {
                    OPE_ENIGMA_DEL();
                }
                else if(choice == 4) {
                    break;
                }
                else {
                    NOTFD();
                }
            }
        }
        else if(choice == 3) {
            while(TRUE) {
                LOCATIZATION_MENU();
                cin>>choice;
                if(choice == 1) {
                    OPE_LOC_SAVE();
                }
                else if(choice == 2) {
                    OPE_LOC_LOAD();
                }
                else if(choice == 3) {
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
        else if(choice == 4) {
            if(OPE_LOC_AUTOSAVE() != OK) {
                cout<<"自动保存失败，是否继续退出"<<endl;
                cout<<"1.是 2.否 3.进行保存后退出"<<endl;
                cin>>choice;
                if(choice == 1) {
                    break;
                }
                else if(choice == 3) {
                    OPE_LOC_SAVE();
                    break;
                }
            }
            else {
                break;
            }
        }
        else {
            NOTFD();
        }

    }
    return 0;
}
