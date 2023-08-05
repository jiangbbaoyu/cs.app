//
// Created by root on 23-8-5.
//


/*
 * Compute (float) f
 * If conversion cause overflow or f is NaN, return 0x80000000
 */

typedef unsigned  float_bits;

int float_f2i(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7F;

    int num;
    unsigned E;
    unsigned M;

    /*
     * consider positive numbers
     *
     * 0 00000000 00000000000000000000000
     *   ===>
     * 0 01111111 00000000000000000000000
     *   0 <= f < 1
     * get integer 0
     *
     * 0 01111111 00000000000000000000000
     *   ===>
     * 0 (01111111+31) 00000000000000000000000
     *   1 <= f < 2^31
     * integer round to 0
     *
     * 0 (01111111+31) 00000000000000000000000
     *   ===>
     * greater
     *   2^31 <= f < oo
     * return 0x80000000
     */
    if (exp >= 0 && exp < 0 + bias) {
        /* number less than 1 */
        num = 0;
    } else if (exp >= 31 + bias) { // E= exp-bias >=31
        /* to big, number overflow !! */
        /* or f < 0 and (int)f == INT_MIN */
        num = 0x80000000;
    } else {
        E = exp - bias;
        M = frac | 0x800000;  // M = 1 + frac
        if (E > 23) {  // 23<E<31
            /*this case is safe */
            num = M << (E - 23);  // threat M as an integer (already shift left 23 positions implicitly ) ,23<E<31 means num > M  and M will shift right E - 23 positions
        } else { // 1<=E <=23
            /* round may occur !! */
            num = M >> (23 - E);  // threat M as an integer (already shift left 23 positions implicitly ) ,1<=E <=23 means num <= M and M will shift left 23-E positions
        }
    }

    return sig ? -num : num;
}
