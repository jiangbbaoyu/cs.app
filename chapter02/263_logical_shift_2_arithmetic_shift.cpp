//
// Created by root on 23-7-21.
//
#include <assert.h>

/**
 * arithmetic shift right to implement logical shift right
 * @param x
 * @param k
 * @return
 */
unsigned  srl(unsigned x, int k){
    unsigned xsra = (int)x >> k;

    int w_len = sizeof (int) <<3;
    int offset = w_len-k;
    int mask = (int)-1 <<offset;  //  1...1 0..0 , ~mask 0..0 1...1
                                  //    k                  k
    return xsra & (~mask);
}
/**
 * logical shift right to implement arithmetic shift right
 * @param x
 * @param k
 * @return
 */
int sra(int x, int k){
    int xsrl = (unsigned )x >>k;

    int w_len = sizeof (int) <<3;
    int offset = w_len-k;
    int mask = (int)-1 <<offset;  //  1...1 0..0
                                  //    k
    int leading_bit = 1<<(w_len-1);
    // //let mask remain unchanged when the first bit of x is 1, otherwise 0.

    // if the leading bit of x is one, leading_bit & x > 0,
    //      then !(leading_bit & x) is 0,  !(leading_bit & x) -1 is -1 (111.1111) ,
    //      mask & 111...111 == mask  (mask unchanged ) , xsrl | mask  will change the right k bits of xsrl to one
    // if the leading bit of x is zero, leading_bit & x == 0,
    //      then !(leading_bit & x) is 1,  !(leading_bit & x) 0 is -1 (000...000) ,
    //      mask & 000...000 == 000...000 (mask change to 0 ) ,  xsrl | mask == xsrl
    mask  = mask & (!(leading_bit & x) -1);

    return xsrl | mask;
}

int main(){
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    assert (srl (test_unsigned, 4) == test_unsigned >> 4);
    assert (sra (test_int, 4) == test_int >> 4);
}