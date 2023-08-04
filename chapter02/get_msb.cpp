//
// Created by root on 23-7-21.
//

#include "utils.h"
#include <limits.h>
#include <assert.h>

/**
 * get most significant byte from x
 * @param x
 * @return
 */
int get_msb(int x){
    int shift_val = (sizeof (int)-1) <<3;
    int xright = x>>shift_val; // arithmetic shift (supply 1 or 0 according to leading bit )

    show_int(xright);
    int lsb = xright & 0xff; // zero all bits but least significant byte
    show_int(lsb);
    return lsb;
}

int main(){
    show_int(INT_MIN);
    assert(get_msb(INT_MIN)==128); // ....  1000 0000

    show_int(INT_MAX);
    assert(get_msb(INT_MAX)==127);//.... 0111 1111

}
