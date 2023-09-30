#ifndef TASK_1_2_CIPHER_H
#define TASK_1_2_CIPHER_H
#include <string>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
extern const int Fibonacci[];
class Cipher {
    private:
    vector<string> message;
    vector<int> key;

    bool validNumber(int value);

    void setMessage();
    void setKey();

    void printMessage();
    void printKey();

    void decodeUserInput();
    void decodeOutput();

    void encodeUserInput();
    void encodeOutput();

    void Decode();
    void Encode();

    friend void decodeProcedure();
    friend void encodeProcedure();
};


#endif //TASK_1_2_CIPHER_H
