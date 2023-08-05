//
// Created by root on 23-8-5.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

void* my_calloc(size_t nmemb, size_t size){
    if (nmemb == 0 || size == 0){
        return NULL;
    }
    size_t buf_size = nmemb * size;
    if( nmemb == buf_size/size) {  /* a good way to check overflow or not */
        void* ptr = malloc(buf_size);
        if(ptr!= NULL) {
            memset(ptr,0,buf_size);
        }
        return ptr;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    void* p;
    p = my_calloc(0x1234, 1);
    assert(p != NULL);
    free(p);

    p = my_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
    return 0;
}