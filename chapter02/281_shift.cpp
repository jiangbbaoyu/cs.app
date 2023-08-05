//
// Created by root on 23-8-5.
//

#include <stdio.h>
#include <assert.h>

/* Assume 0 <= k < w */
int A(int k) {
    return (unsigned )-1 << k;
}

/* Assume 0 <= j,k < w */
int B(int k, int j) {
    /**
     * eg j=3 k=4
     *    A(k)          ~A(k)       ~A(k)<<j
     *    11110000      00001111    01111000
     */
    return   ~A(k)<< j;
}

int main(int argc, char* argv[]) {
    assert(A(8) == 0xFFFFFF00);
    assert(B(16, 8) == 0x00FFFF00);
    return 0;
}

