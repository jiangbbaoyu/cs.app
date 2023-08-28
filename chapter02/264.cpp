//
// Created by root on 23-7-21.
//
#include <assert.h>

int any_odd_one(unsigned x){
    return !! (0x55555555 & x );
}

int main(){

    assert(any_odd_one(0x01));
    assert(!any_odd_one(0x02));
    assert(any_odd_one(0x03));

}