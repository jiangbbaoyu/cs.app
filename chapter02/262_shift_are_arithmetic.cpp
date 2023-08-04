//
// Created by root on 23-7-21.
//
#include <assert.h>

int shift_are_arithmetic(){
    int num = -1 ; // 111...111
    return !(num ^ (num>>1) );
}

int main(){
    assert(shift_are_arithmetic());
}