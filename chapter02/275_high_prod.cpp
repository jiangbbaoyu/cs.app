//
// Created by root on 23-8-5.
#include <inttypes.h>
#include <assert.h>

int signed_high_prod(int x,int y){
    int64_t  prod =(int64_t) x * y;
    return prod >> (sizeof(int) <<3);
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int x_sign = x >>31;
    int y_sign = y>>31;
    int signed_high_prod_val = signed_high_prod(x,y);

    return signed_high_prod_val + x_sign* y + y_sign*x;
}


/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
    uint64_t mul = (uint64_t) x * y;
    return mul >> 32;
}

int main(int argc, char* argv[]) {
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}
