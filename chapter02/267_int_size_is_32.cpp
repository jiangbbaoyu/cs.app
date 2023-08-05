//
// Created by root on 23-8-4.
//


// If the value of the right operand
// is negative or is `greater than or equal to` the width of the promoted left operand,
// the behavior it undefined.
/*
int bad_int_size_is_32() {
  int set_msb = 1 << 31;
  int beyond_msb = 1 << 32;

  return set_msb && !beyond_msb;
}
*/
#include <assert.h>

int int_size_is_32(){
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && ! beyond_msb;
}


int int_size_is_32_for16(){
    int set_msb = 1 << 15 << 15 << 1 ;
    int beyond_msb = set_msb << 1;
    return set_msb && ! beyond_msb;
}

int main(){
    assert(int_size_is_32());
    assert(int_size_is_32_for16());
}