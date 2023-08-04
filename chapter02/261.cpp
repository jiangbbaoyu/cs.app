//
// Created by root on 23-7-21.
//
#include <assert.h>

int A(int x) {
    return !~x;
}

int B(int x) {
    return !x;
}

int C(int x) {
    return !~(x | ~0xff);
}

int D(int x){
    return !(x >>((sizeof (int )-1)<<3)) ;
//    return B((x >> ((sizeof(int)-1) << 3)) & 0xff);
}

int is_true(int x){
    return A(x) | B(x) | C(x) | D(x);
}

int main(){

    int all_bit_one = ~0;
    int all_bit_zero = 0;

    assert(A(all_bit_one));
    assert(!B(all_bit_one));
    assert(C(all_bit_one));
    assert(!D(all_bit_one));

    assert(!A(all_bit_zero));
    assert(B(all_bit_zero));
    assert(!C(all_bit_zero));
    assert(D(all_bit_zero));

    // test magic number 0xff1234ff
    assert(is_true(0xff1234ff));
    assert(!A(0xff1234ff));
    assert(!B(0xff1234ff));
    assert(C(0xff1234ff));
    assert(!D(0xff1234ff));

    // test magic number 0x1234
    assert(!A(0x1234));
    assert(!B(0x1234));
    assert(!C(0x1234));
    assert(D(0x1234));

}


