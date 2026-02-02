/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32 */
#include <stdlib.h>
#include <stdio.h>

int any_odd_one(unsigned x){
    // 1's in odd positions, 0 in even positions

    unsigned w = 0xAAAAAAAA ;

    unsigned B = x & w;

    return !!B ;
    // when equal -> !0 = 0x01
    // when differetn -> !1 = 0x00

};

int main() {

    unsigned n = 0x55555555 ;

    int result = any_odd_one(n) ;

    printf("result: %x", result) ;

    return 0 ;
}
