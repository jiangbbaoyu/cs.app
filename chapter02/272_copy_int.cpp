//
// Created by root on 23-8-4.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void copy_int(int val, void* buf, int maxbytes) {
    // maxbytes - sizeof(val) returns value of type size_t, and it’s always >= 0
//    if (maxbytes -sizeof(int) >=0 ) {
    /* compare two signed number, avoid someone set maxbytes a negetive value */
    if (maxbytes >= (int) sizeof(val)) {
        memcpy(buf, (void*)&val, sizeof(val));
    }
}

int main(){
    int maxbytes = sizeof(int) * 10;
    void* buf = malloc(maxbytes);
    int val;
    val = 0x12345678;
    copy_int(val,buf,maxbytes);
    int val_in_buf = *((int*)buf);
    assert( val== val_in_buf);

    val = 0xAABBCCDD;
    copy_int(val, buf, 0);
    assert(*(int*)buf != val);

    free(buf);
}

