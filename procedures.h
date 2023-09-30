#include "Cipher.h"
#ifndef TASK_1_2_PROCEDURES_H
#define TASK_1_2_PROCEDURES_H
void decodeProcedure(){
    Cipher a;
    a.decodeUserInput();
    a.Decode();
    a.decodeOutput();
}
void encodeProcedure(){
    Cipher a;
    a.encodeUserInput();
    a.Encode();
    a.encodeOutput();
}
#endif //TASK_1_2_PROCEDURES_H
