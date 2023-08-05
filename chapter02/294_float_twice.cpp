//
// Created by root on 23-8-5.
//

typedef unsigned  float_bits ;

float_bits float_twice(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = (f >> 24) & 0xff;
    unsigned frac = f & 0x7fffff;

    int is_NAN_or_oo = (exp == 0xFF);
    if (is_NAN_or_oo) {
        return f;
    }

    if (exp == 0) {
        /* Denormalized */
        frac <<= 1;
    } else if (exp == 0xFF - 1) {
        /* twice to oo */
        exp = 0xFF;
        frac = 0;
    } else {
        /* Normalized */
        exp += 1;
    }

    return sign << 31 | exp << 23 | frac;


}
