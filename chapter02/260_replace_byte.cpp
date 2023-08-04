//
// Created by root on 23-7-20.
//
#include <assert.h>
#include <stdio.h>
typedef unsigned char *byte_pointer;
unsigned  replace_byte(unsigned x,int i,unsigned  char b){
    if (i<0){
        printf("error: i is negetive\n");
        return x;
    }
    if (i>sizeof(unsigned)-1){
        printf("error: i is too big");
        return x;
    }

    byte_pointer p = (byte_pointer)&x;
    p[i] = b;
    return *((unsigned *)p);
}

unsigned  replace_byte2(unsigned x,int i,unsigned  char b){
    if (i<0){
        printf("error: i is negetive\n");
        return x;
    }
    if (i>sizeof(unsigned)-1){
        printf("error: i is too big");
        return x;
    }

    unsigned mask = ((unsigned )0xff) << (i<<3);
    unsigned byte_in_pos = ((unsigned )b) << (i<<3);

    return (~mask & x) | byte_in_pos;
}

int main(){
//    unsigned rep_0 = replace_byte(0x12345678, 0, 0xAB);
//    unsigned rep_3 = replace_byte(0x12345678, 3, 0xAB);

    unsigned rep_0 = replace_byte2(0x12345678, 0, 0xAB);
    unsigned rep_3 = replace_byte2(0x12345678, 3, 0xAB);

    assert(rep_0 == 0x123456AB);
    assert(rep_3 == 0xAB345678);
}