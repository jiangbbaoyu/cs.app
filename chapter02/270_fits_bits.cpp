//
// Created by root on 23-8-4.
//
#include <assert.h>

/**
* return 1 when x can be represented as an n-bit, 2's-complement number
* 0 otherwise
* assume 1<= n <= w
*/

int fits_bits(int x, int n){
  /*
   * 1 <= n <= w
   * assume w = 8, n = 3
   * if x > 0
   *   0b00000 010 is ok, 0b00001 010 is not, and 0b00000 110 is not yet (x > 0 while 2's-complement 110 represent negative number )
   * if x < 0
   *   0b11111 100 is ok, 0b10111 100 is not, and 0b11111 000 is not yet
   *
   * the point is
   *   x << (w-n) >> (w-n) must be equal to x itself.
   *
   *   x                 x << (w-n)          x << (w-n) >> (w-n)    res
   *   0b00000 010       0b010 00000         0b00000 010            Y
   *   0b00001 010       0b010 00000         0b00000 010            N
   *   0b00000 110       0b110 00000         0b11111 110            N
   *   0b11111 100       0b100 00000         0b11111 100            Y
   *   0b10111 100       0b100 00000         0b11111 100            N
   *   0b11111 000       0b000 00000         0b00000 000            N
   */

    int w = sizeof (int ) >> 3;
    int offset = w-n;
    return (x << offset >> offset)  == x; // x << (w-n) >> (w-n) must be equal to x itself.
}

int main(){
    assert(!fits_bits(0xFF, 8));
    assert(!fits_bits(~0xFF, 8));

    assert(fits_bits(0b0010, 3));
    assert(!fits_bits(0b1010, 3));
    assert(!fits_bits(0b0110, 3));

    assert(fits_bits(~0b11, 3));
    assert(!fits_bits(~0b01000011, 3));
    assert(!fits_bits(~0b111, 3));
}