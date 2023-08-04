//
// Created by root on 23-7-21.
//

#ifndef CS_APP_UTILS_H
#define CS_APP_UTILS_H

#include <stdio.h>
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

void show_float(float f){
    show_bytes((byte_pointer)&f, sizeof(float));
}

void show_pointer(void *ptr){
    show_bytes((byte_pointer)&ptr, sizeof(void*));
}
void show_double(double x) {
    show_bytes((byte_pointer)&x, sizeof(double));
}

#endif //CS_APP_UTILS_H
