//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#ifndef MENU_H

#define OK 1
#define ERROR -1
#define NOTFOUND 0
#define TRUE 1
#define FALSE 0

ListNode *head = NULL;
ListNode *temp = NULL;
ListNode *p = NULL;

inline void MENU1() {
    std::cout<<std::endl;
    std::cout<<"请输入您的操作"<<std::endl;
    std::cout<<"1.新建密码"<<std::endl;
    std::cout<<"2.查询密码"<<std::endl;
    std::cout<<"3.解密密码"<<std::endl;
    std::cout<<"4.删除密码"<<std::endl;
    std::cout<<"5.退出程序"<<std::endl;
}

inline void OPE_ADD() { //添加新密码 OPE_ADD
    int key;
    std::string website,password;

    std::cout<<"请输入网站名"<<std::endl;
    std::cin>>website;
    std::cout<<"请输入密码"<<std::endl;
    std::cin>>password;
    std::cout<<"请输入转子"<<std::endl;
    std::cin>>key;
    Encrypt(password,key);
    p = new ListNode();
    if(ListAdd(head,p,password,website) == OK) {
        std::cout<<"新建完成"<<std::endl;
    }
    else {
        std::cout<<"发生错误"<<std::endl;
    }
}

inline void OPE_SEE() { //查询所有密码 OPE_SEE
    if(ListPrint(head) == OK) {
        std::cout<<"查询完毕"<<std::endl;
    }
    else {
        std::cout<<"发生错误"<<std::endl;
    }
}

inline void OPE_DRT() { //解密密码 OPE_DECRYPT
    int key,reply;
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
        std::cout<<"请输入转子"<<std::endl;
        std::cin>>key;
        std::cout<<"解密前密码为:"<<_temp<<std::endl;
        Decrypt(_temp,key);
        std::cout<<"解密后密码为:"<<_temp<<std::endl;
    }
}

inline void OPE_DEL() { //删除密码 OPE_DELETE
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

inline void OPE_NFD() { //未找到 OPE_NOTFOUND
    std::cout<<"未找到该操作"<<std::endl;
}
#endif //MENU_H
