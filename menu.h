//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#ifndef MENU_H
#define MENU_H

#define OK 1
#define ERROR -1
#define NOTFOUND 0
#define TRUE 1
#define FALSE 0

class CENIGMA {
public:
    int amount;
    int rotor[8];

};

int rotor_amt = 1; //恩尼格码数量
CENIGMA ENIGMA[100]; //恩尼格码

ListNode *head = NULL;
ListNode *temp = NULL;
ListNode *p = NULL;

inline void MAIN_MENU() {
    std::cout<<std::endl;
    std::cout<<"请输入您的操作"<<std::endl;
    std::cout<<"1.密码相关菜单"<<std::endl;
    std::cout<<"2.恩尼格码菜单"<<std::endl;
    std::cout<<"3.退出程序"<<std::endl;
}

inline void PWD_MENU() {
    std::cout<<"请输入您的操作"<<std::endl;
    std::cout<<"1.新建密码"<<std::endl;
    std::cout<<"2.查询密码"<<std::endl;
    std::cout<<"3.解密密码"<<std::endl;
    std::cout<<"4.删除密码"<<std::endl;
    std::cout<<"5.返回上级"<<std::endl;
}

inline void ENIGMA_MENU() {
    std::cout<<"请输入您的操作"<<std::endl;
    std::cout<<"1.新建恩尼格码"<<std::endl;
    std::cout<<"2.查询恩尼格码"<<std::endl;
    std::cout<<"3.删除恩尼格码"<<std::endl;
    std::cout<<"4.返回上级"<<std::endl;
}

inline void NOTFD() { //未找到 NOTFOUND
    std::cout<<"未找到该操作"<<std::endl;
}




/////密码相关/////

inline void OPE_PWD_ADD() { //添加新密码 PWD_ADD
    int no;
    std::string website,password;

    std::cout<<"请输入网站名"<<std::endl;
    std::cin>>website;
    std::cout<<"请输入密码"<<std::endl;
    std::cin>>password;
    std::cout<<"要使用几号恩格尼码"<<std::endl;
    std::cin>>no;
    std::string stemp;
    for(int i = 0; i < ENIGMA[no].amount; i++) {
        stemp += std::to_string(i);
        Encrypt(password,ENIGMA[no].rotor[i]);
    }
    password += stemp;
    p = new ListNode();
    if(ListAdd(head,p,password,website) == OK) {
        std::cout<<"新建完成"<<std::endl;
    }
    else {
        std::cout<<"发生错误"<<std::endl;
    }
}

inline void OPE_PWD_SEE() { //查询所有密码 PWD_SEE
    if(ListPrint(head) == OK) {
        std::cout<<"查询完毕"<<std::endl;
    }
    else {
        std::cout<<"发生错误"<<std::endl;
    }
}

inline void OPE_PWD_DRT() { //解密密码 PWD_DECRYPT
    int no,reply;
    std::string _temp;
    std::cout<<"要解密几号密码"<<std::endl;
    int num;
    std::cin>>num;

    reply = PWDtake(head,num,_temp);
    if(reply == ERROR) {
        std::cout<<"发生错误"<<std::endl;
    }
    else if (reply == NOTFOUND) {
        std::cout<<"未找到"<<std::endl;
    }
    else if (reply == OK) {
        std::cout<<"使用几号恩尼格码解密"<<std::endl;
        std::cin>>no;
        std::cout<<"解密前密码为:"<<_temp<<std::endl;
        for(int i = 0; i < ENIGMA[no].amount; i++) {
            _temp.pop_back();
        }
        for(int i = ENIGMA[no].amount-1; i >= 0; i--) {
            Decrypt(_temp,ENIGMA[no].rotor[i]);
        }
        std::cout<<"解密后密码为:"<<_temp<<std::endl;
    }
}

inline void OPE_PWD_DEL() { //删除密码 PWD_DELETE
    int reply;
    std::cout<<"要删除几号密码"<<std::endl;
    int num;
    std::cin>>num;

    reply = ListDel(head,num);
    if(reply == OK) {
        std::cout<<"删除成功"<<std::endl;
    }
    else if (reply == NOTFOUND) {
        std::cout<<"未找到"<<std::endl;
    }
    else if (reply == ERROR){
        std::cout<<"发生错误"<<std::endl;
    }
}





/////恩尼格码相关/////

inline void ENIGMA_INIT() {
    for(int i = 0; i < 100; i++) {
        ENIGMA[i].amount = -1;
    }
}

inline void OPE_ENIGMA_ADD() {
    std::cout<<"请输入转子总数"<<std::endl;
    std::cin>>ENIGMA[rotor_amt].amount;
    for(int i = 0; i < ENIGMA[rotor_amt].amount; i++) {
        std::cout<<"请输入"<<i+1<<"号转子的数值"<<std::endl;
        std::cin>>ENIGMA[rotor_amt].rotor[i];
    }
    if(ENIGMA[rotor_amt].amount == -1) {std::cout<<"发生错误"<<std::endl;}
    rotor_amt++;
    std::cout<<"添加成功"<<std::endl;
}

inline void OPE_ENIGMA_PRT() {
    std::cout<<"编号  "<<"转子数量 "<<"转子"<<std::endl;
    for(int i = 1; i < rotor_amt; i++) {
        std::cout<<std::left<<std::setw(5)<<i;
        std::cout<<std::left<<std::setw(8)<<ENIGMA[i].amount;
        for(int j = 0; j < ENIGMA[i].amount; j++) {
            std::cout<<ENIGMA[i].rotor[j]<<" ";
        }
        std::cout<<std::endl;
    }
}

inline void OPE_ENIGMA_DEL() {
    int no;
    std::cout<<"要删除几号恩尼格码"<<std::endl;
    std::cin>>no;
    for(int i = no ; i < rotor_amt; i++) {
        ENIGMA[i].amount = ENIGMA[i+1].amount;
        for(int j = 0; j < ENIGMA[i].amount; j++) {
            ENIGMA[i].rotor[j] = ENIGMA[i+1].rotor[j];
        }
    }
    rotor_amt--;
}
#endif //MENU_H
