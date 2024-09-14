//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#ifndef DATA_H
#define OK 1
#define ERROR -1
#define NOTFOUND 0
#define TRUE 1
#define FALSE 0
#define NULL nullptr

#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

class DT {
    public:
    std::string password;
    std::string website;
};

class ListNode {
    public:
    DT data;
    ListNode* next{};
};

inline int ListInit (ListNode* &L) {
    L = new ListNode;
    if(!L) return ERROR;

    L -> next = NULL;

    return OK;
}

inline int ListAdd (ListNode* &L,ListNode* &Node,const std::string& pwd,const std::string& web) {
    if(!L) return ERROR;
    ListNode *p;
    p=L;
    while(p->next != NULL && !p) {
        p=p->next;
    }

    Node->data.password=pwd;
    Node->data.website=web;
    Node->next = p->next;
    p->next = Node;
    return OK;
}

// inline int insert (ListNode* &L,const std::string& pwd,const std::string& web,int i) {
//     if(!L) return ERROR;
//     ListNode *p,*s;
//     p=L;
//     int j = 0;
//     while(p&&j<i-1) {
//         p=p -> next;
//         j++;
//     }
//     if(!p || j > i-1) return ERROR;
//
//     s = new ListNode;
//     s->data.password = pwd;
//     s->data.website = web;
//     s->next = p->next;
//     p->next = s;
//     return OK;
// }

inline int PWDtake (ListNode* &L,int i,std::string &s) {
    if(!L) return ERROR;
    ListNode *p;
    p = L;
    int j = 0;
    while(j < i && p) {
        p = p->next;
        j++;
    }
    if(!p || j > i) return NOTFOUND;

    s = p->data.password;
    return OK;
}

inline int ListDel (ListNode* &L,int i) {
    if(!L) return ERROR;
    ListNode *p;
    p = L;
    int j = 0;
    while(j < i-1 && p) {
        p = p->next;
        j++;
    }
    if(!p || j > i-1) return NOTFOUND;

    p->next = p->next->next;
    return OK;
}

inline int ListPrint (ListNode* &L) {
    if(!L) return ERROR;
    std::cout<<"所有密码如下"<<std::endl;;
    ListNode *p;
    p = L;
    int count = 0;
    std::cout<<"编号  "<<"网站                 "<<"密码"<<std::endl;
    while(p->next != NULL) {
        p = p -> next;
        count++;
        std::cout<<std::left<<std::setw(5)<<count;
        std::cout<<std::left<<std::setw(20)<<p->data.website;
        std::cout<<p->data.password<<std::endl;
    }
    return OK;
}

inline int PWDsearch (ListNode* &L,const std::string& pwd,int &i) {
    if(!L) return ERROR;
    ListNode *p;
    p = L;
    while(p->next != NULL) {
        if(p->data.password == pwd ) {return OK;}
        p = p -> next;
    }

    return NOTFOUND;
}

inline int WEBsearch (ListNode* &L,const std::string& web,int &i) {
    if(!L) return ERROR;
    ListNode *p;
    p = L;
    while(p->next != NULL) {
        if(p->data.website == web ) {return OK;}
        p = p -> next;
    }

    return NOTFOUND;
}

#endif
