//
// Created by root on 23-8-4.
//

/*
 * Generate mask indicating leftmost 1 in x. Assume w=32
 * For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
 * If x = 0, then return 0
 */
#include <assert.h>
int leftmost_one(unsigned x){

    /*
   * first, generate a mask that all bits after leftmost one are one
   * e.g. 0xFF00 -> 0xFFFF, and 0x6000 -> 0x7FFF
   * If x = 0, get 0
   */

    x = x | x>>1;
    x = x | x>>2;
    x = x | x>>4;
    x = x | x>>8;
    x = x | x>>16;

//    return (x >> 1) + 1 ;   // don't consider x==0,
    return (x >> 1) + (x && 1) ; // if x ==0 , x && 1 == 0 , and finally return 0

}

int main(){
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x6000) == 0x4000);
    assert(leftmost_one(0x0) == 0x0);
    assert(leftmost_one(0x80000000) == 0x80000000);
}