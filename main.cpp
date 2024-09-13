//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#include <iostream>
#include "password.h"
#include "data.h"

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
    ListNode *head = NULL;
    ListNode *temp = NULL;
    ListNode *p = NULL;
    int key,reply;

    ListInit(head);
    while(TRUE) {
        cout<<endl;
        cout<<"请输入您的操作"<<endl;
        cout<<"1.新建密码"<<endl;
        cout<<"2.查询密码"<<endl;
        cout<<"3.解密密码"<<endl;
        cout<<"4.删除密码"<<endl;
        cout<<"5.退出程序"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1) {
            string website,password;
            cout<<"请输入网站名"<<endl;
            cin>>website;
            cout<<"请输入密码"<<endl;
            cin>>password;
            cout<<"请输入转子"<<endl;
            cin>>key;
            Encrypt(password,key);
            p = new ListNode();
            if(ListAdd(head,p,password,website) == OK) {
                cout<<"新建完成"<<endl;
            }
            else {
                cout<<"发生错误"<<endl;
            }
        }
        else if(choice == 2) {
            if(ListPrint(head) == OK) {
                cout<<"查询完毕"<<endl;
            }
            else {
                cout<<"发生错误"<<endl;
            }
        }
        else if(choice == 3) {
            string _temp;
            cout<<"要解密几号密码"<<endl;
            int num;
            cin>>num;

            reply = PWDtake(head,num,_temp);
            if(reply == ERROR) {
                cout<<"发生错误"<<endl;
            }
            else if (reply == NOTFOUND) {
                cout<<"未找到"<<endl;
            }
            else if (reply == OK) {
                cout<<"请输入转子"<<endl;
                cin>>key;
                cout<<"解密前密码为:"<<_temp<<endl;
                Decrypt(_temp,key);
                cout<<"解密后密码为:"<<_temp<<endl;
            }
        }
        else if(choice == 4) {
            cout<<"要删除几号密码"<<endl;
            int num;
            cin>>num;

            reply = ListDel(head,num);
            if(reply == OK) {
                cout<<"删除成功"<<endl;
            }
            else if (reply == NOTFOUND) {
                cout<<"未找到"<<endl;
            }
            else if (reply == ERROR){
                cout<<"发生错误"<<endl;
            }
        }
        else if(choice == 5) {
            break;
        }
        // else if(choice == 999) {
        //     string s;
        //     s = head->next->data.password;
        //     cout<<s;
        // }
        else {
            cout<<"未找到该操作"<<endl;
        }

    }
    return 0;
}
