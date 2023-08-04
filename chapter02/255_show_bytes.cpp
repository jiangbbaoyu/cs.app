//
// Created by root on 23-7-15.
//
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

int main(){
    int x =0xff;
    float f= x;
    double d =x;
    int* iptr = &x;

    show_int(x);
//    show_float(f);
//    show_pointer(iptr);
//    show_double(d);
    return 0;
}

