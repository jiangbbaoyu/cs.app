//
// Created by root on 23-8-5.
//


typedef unsigned  float_bits ;

float_bits float_negate(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = (f >> 24) & 0xff;
    unsigned frac = f & 0x7fffff;

    float_bits res = 0<<31 | exp <<23 | frac;

    int is_nan = (exp==0xff) && (frac!=0);
    is_nan && (res = f);

    return res;
}