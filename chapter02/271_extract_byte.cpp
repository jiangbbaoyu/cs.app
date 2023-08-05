//
// Created by root on 23-8-4.
//
#include <assert.h>

typedef  unsigned  packed_t;
/**
 *  extract nth byte from word , return the byte and padding zeros in left
 *  eg: word = 1000000 00000000 10000000 00000000,
 *  when n=0 , return 0
 *  when n=1,  return 00000000 0000000 00000000 10000000  ( 00000000 1000000 00000000 10000000 & 0xff = 00000000 0000000 00000000 10000000)
 * @param word
 * @param bytenum
 * @return
 */
int xbyte1(packed_t word, int n){
    return  ( word >> (n << 3 ) )  & 0xff;
}

/**
 *  extract nth byte from word , return the byte as a 2's-complement (padding zeros or ones according to leading bit of the byte)
 *  eg: word = 1000000 00000000 10000000 00000000,
 *  when n=0 , return 0
 *  when n=1,
 *      (int)word << ((max_bytenum -n) << 3)  :  10000000 00000000 00000000 00000000
 *      (int)word << ((max_bytenum -n) << 3)  >> (max_bytenum << 3):    11111111 11111111 11111111 10000000  ( the value equals 10000000 in 2's-complement )
 * @param word
 * @param bytenum
 * @return
 */
int xbyte2(packed_t word, int n){
    int max_bytenum = 3;
    return (int)word << ((max_bytenum -n) << 3)  >> (max_bytenum << 3);
}

int main(){
    assert(xbyte2(0x00112233, 0) == 0x33);
    assert(xbyte2(0x00112233, 1) == 0x22);
    assert(xbyte2(0x00112233, 2) == 0x11);
    assert(xbyte2(0x00112233, 3) == 0x00);

    assert(xbyte2(0xAABBCCDD, 0) == 0xFFFFFFDD);
    assert(xbyte2(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte2(0xAABBCCDD, 2) == 0xFFFFFFBB);
    assert(xbyte2(0xAABBCCDD, 3) == 0xFFFFFFAA);
}


