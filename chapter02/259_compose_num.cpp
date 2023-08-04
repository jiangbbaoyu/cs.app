//
// Created by root on 23-7-20.
//
#include <stdio.h>
#include <assert.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for(i=0;i<len;i++){
        printf("address: %p   hex value:  %.2x \n",start +i, start[i]);
    }
    printf("\n");
}


void show_int(int x){
    show_bytes((byte_pointer)&x, sizeof(int));
}

int main(){
    int mask = 0xff;
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int res = (x & mask) | (y & ~mask);  // using mask to extract `least byte` and `bytes except least byte`
    show_int(res);
    assert(res == 0x765432EF);
}