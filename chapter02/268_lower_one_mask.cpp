//
// Created by root on 23-8-4.
//
#include <assert.h>

/*
 * Mask with least signficant n bits set to 1
 * Example: n = 6 -> 0x3F, n = 17 -> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n){
    int w = sizeof (int ) << 3;
    // -1 in unsigned , all bits are one,
    // and logical shift left w-n  position  will pad w-n zeros in left
    return (unsigned ) -1  >> (w -n);
}

int main(){
    assert(lower_one_mask(1) == 0x1);
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
}
