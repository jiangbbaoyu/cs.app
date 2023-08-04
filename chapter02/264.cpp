//
// Created by root on 23-7-21.
//
#include <assert.h>

int any_odd_one(unsigned x){
    return !! (0x55555555 & x );
}

int all_odd_one(unsigned x){
    return ! ((0xAAAAAAAA | x) +1 );
}

int main(){

    assert(any_odd_one(0x01));
    assert(!any_odd_one(0x02));
    assert(any_odd_one(0x03));

    assert(all_odd_one(0x55555555));
    assert(!all_odd_one(0x55555556));
    assert(all_odd_one(0x55555557));


}