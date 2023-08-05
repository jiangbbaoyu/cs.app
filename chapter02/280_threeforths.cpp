//
// Created by root on 23-8-5.
//

#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * calculate 3/4x, no overflow, round to zero
 *
 * no overflow means divide 4 first, then multiple 3, diffrent from 2.79 here
 *
 * rounding to zero is a little complicated.
 * every int x, equals f(first 30 bit number) plus l(last 2 bit number)
 *   f = x & ~0x3
 *   l = x & 0x3
 *   x = f + l
 *   threeforths(x) =  (f+l)*3/4 =  f/4*3 + l*3/4
 *
 * f doesn't care about round at all, we just care about rounding from l*3/4
 *
 *   lm3 = (l << 1) + l
 *
 * when x > 0, rounding to zero is easy
 *
 *   lm3d4 = lm3 >> 2
 *
 * when x < 0, rounding to zero acts like divide_power2 in 2.78
 *
 *   bias = 0x3    // (1 << 2) - 1
 *   lm3d4 = (lm3 + bias) >> 2
 */

int threeforths(int x) {
    int neg = x & INT_MIN;
    int l = x & 0x03;
    int f = x & (~0x03);

    int fd4 = f>>2;
    int fd4m3 = fd4 + (fd4 <<1);


    int lm3 = l + (l<<1);
    neg && (lm3 = lm3+(1<<2)-1);
    int lm3d4 = lm3 >> 2;

    return lm3d4 + fd4m3;
}

int main(int argc, char* argv[]) {
    assert(threeforths(8) == 6);
    assert(threeforths(9) == 6);
    assert(threeforths(10) == 7);
    assert(threeforths(11) == 8);
    assert(threeforths(12) == 9);

    assert(threeforths(-8) == -6);
    assert(threeforths(-9) == -6);
    assert(threeforths(-10) == -7);
    assert(threeforths(-11) == -8);
    assert(threeforths(-12) == -9);
    return 0;
}