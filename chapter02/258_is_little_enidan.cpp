//
// Created by root on 23-7-20.
//
#include <stdio.h>
#include <assert.h>
typedef unsigned char* byte_pointer;
int is_little_endian(){
    int num =0xff;
    byte_pointer  pointer = (byte_pointer)&num;
    if (pointer[0] ==0xff){
        return 1;  // little endian,  low bits in low memory position
    }else {
        return 0; // big endian
    }
}

int main(){
    printf("%d\n",is_little_endian());
    assert(is_little_endian());
}