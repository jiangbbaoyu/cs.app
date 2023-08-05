
//
// Created by root on 23-8-4.
//
#include <assert.h>

// 0 <= n < w
unsigned rotate_left(unsigned x, int n){
    int w = sizeof(unsigned) << 3;
    // don't consider n == 0,  w-n == w
    // If the value of the right operand is `greater than or equal to` the width of the promoted left operand,
    // the behavior it undefined.
    // int left = x >> (w-n);  // when n ==0 , left == x

    int left = x >> (w-n-1) >> 1;  // when n ==0 , left ==0
    int right = x << n;
    return left | right;  // left + right
}

int main(){
    assert(rotate_left(0x12345678, 0) == 0x12345678);
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
}
