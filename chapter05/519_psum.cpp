//
// Created by root on 23-10-15.
//


#include <stdio.h>
#include <assert.h>

void psum1a(float a[], float p[], long n) {
    long i;
    float last_val, val;
    last_val = p[0] = a[0];
    for (i = 1; i < n; i++) {
        val = last_val + a[i];
        p[i] = val;
        last_val = val;
    }
}

/* version 4*1a */
void psum_4_1a(float a[], float p[], long n) {
    long i;
    float val, last_val;
    float tmp, tmp1, tmp2, tmp3;
    last_val = p[0] = a[0];

    for (i = 1; i < n - 4; i=i+4) {
        tmp = last_val + a[i];
        tmp1 = tmp + a[i+1];
        tmp2 = tmp1 + a[i+2];
        tmp3 = tmp2 + a[i+3];

        p[i] = tmp;
        p[i+1] = tmp1;
        p[i+2] = tmp2;
        p[i+3] = tmp3;

        /* key point */
        last_val = last_val + (a[i] + a[i+1] + a[i+2] + a[i+3]);
    }

    for (; i < n; i++) {
        last_val += a[i];
        p[i] = last_val;
    }
}

#define LOOP 1000
#define LEN  1000

int main(int argc, char* argv[]) {
    float a[10] = { 1, 2, 3, 4, 5 ,6,7,8,9,10};
    float p[10];
    psum1a(a, p, 10);
    assert(p[9] == 55);

    float q[10];
    psum_4_1a(a, q, 10);
    assert(q[9] == 55);
    return 0;
}