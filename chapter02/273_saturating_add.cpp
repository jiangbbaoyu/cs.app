//
// Created by root on 23-8-4.
//
#include <limits.h>
#include <assert.h>

int saturating_add (int x,int y) {
    int sum = x + y;
    int sig_mask = INT_MIN;

    // if x > 0, y > 0 but sum < 0, it's a positive overflow  (positive num 's msb is zero)
    int pos_overflow = !(sig_mask & x)  && !(sig_mask & y)  && (sig_mask & sum);

    // if x < 0, y < 0 but sum > 0, it's a negative overflow  (negative num 's msb is one)
    int neg_overflow = (sig_mask & x)  && (sig_mask & y)  && !(sig_mask & sum);

    ( pos_overflow && (sum=INT_MAX) )  || ( neg_overflow && (sum=INT_MIN) );
    return sum ;
}

int main(int argc, char* argv[]) {
    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
    return 0;
}