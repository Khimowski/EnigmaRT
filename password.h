//
// Created by RedTea
// Encode : UTF-8
// IDE : JetBrains CLion
//
#ifndef PASSWORD_H
#define OK 1
#define ERROR -1
#define NOTFOUND 0
#define TRUE 1
#define FALSE 0

#include<string>

inline int Encrypt(std::string &s,int key) {
    for(int i=0;i<s.size();i++) {
        s[i] = (char)(((int)s[i] + key) % 128);
    }
    return OK;
}

inline int Decrypt(std::string &s,int key) {
    for(int i=0;i<s.size();i++) {
        s[i] = (char)(((int)s[i] - key + 128) % 128);
    }
    return OK;
}

#endif