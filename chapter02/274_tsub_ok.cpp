//
// Created by root on 23-8-4.
//
#include <limits.h>
#include <assert.h>

/* Determine whether arguments can be substracted without overflow */
int tsub_ok(int x, int y){
    int res=1;
    int sig_mask = INT_MIN;


    int sub = x -y;
    // x>=0  y<0  x-y<0
    int pos_overflow =  !(x & sig_mask) && (y & sig_mask) && (sub & sig_mask);
    // x<0  y>0  x-y>0
    int neg_overflow =  (x & sig_mask) && !(y & sig_mask) && !(sub & sig_mask);

    (pos_overflow && (res=0) )|| (neg_overflow &&(res=0));

    return res;
}

int main(int argc, char* argv[]) {
    assert(!tsub_ok(1, INT_MIN));
    assert(!tsub_ok(0x00, INT_MIN));
    assert(tsub_ok(-1, INT_MIN));
    assert(tsub_ok(0x00, 0x00));

    assert(!tsub_ok(-100, INT_MAX));

    return 0;
}
