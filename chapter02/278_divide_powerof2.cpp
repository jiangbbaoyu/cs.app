//
// Created by root on 23-8-5.
//
#include <limits.h>
#include <assert.h>

/*
 * Divide by power of 2, -> x/2^k
 * Assume 0 <= k < w-1
 */
int divide_power2(int x,int k){
    int neg = x & INT_MIN;

    // ensure negative number divide round up (negative number and positive number both round to zero,that is x.x -> x  0  -y  <- -y.y )
    (neg && (x=x+(1<<k)-1));  // (1 << k) - 1 :  111........111,  once the lower k bits of x have a one, x+(1<<k)-1)  will generate a carry to low k-1 bit
                                                 // num of k

    return x >>k;
}
int main(int argc, char* argv[]) {
    int x = 0x80000007;
    int x2 =111;

    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    assert(divide_power2(x2, 1) == x2 / 2);
    assert(divide_power2(x2, 2) == x2 / 4);
    return 0;
}
