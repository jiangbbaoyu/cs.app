//
// Created by root on 23-7-31.
//
#include <assert.h>

int odd_ones(unsigned x) {
    x = x ^ x>>16;
    x = x ^ x>>8;
    x = x ^ x>>4;
    x = x ^ x>>2;
    x = x ^ x>>1;

    x = x & 1; // only consider the latest bit, and the result is ether 1 or 0

    return x;
}

int odd_ones2(unsigned x) {
    x = (x & 0x0000ffff) ^ (x>>16);
    x = (x & 0x000000ff) ^ (x>>8);
    x = (x & 0x0000000f) ^ (x>>4);
    x = (x & 0x00000003) ^ (x>>2);
    x = (x & 0x00000001) ^ (x>>1);

    return x;
}

int main(){
    assert(odd_ones(0x10101011));
    assert(!odd_ones(0x101));

    assert(odd_ones2(0x10101011));
    assert(!odd_ones2(0x101));
}


