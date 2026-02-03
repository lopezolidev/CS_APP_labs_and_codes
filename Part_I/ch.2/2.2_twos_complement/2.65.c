/* Return 1 when x contains an odd number of 1s; 0 otherwise.
Assume w=32 */
#include <stdlib.h>
#include <stdio.h>

int odd_ones(unsigned x){
    // LSB is the parity bit -> 1: odd , 0: even
    // 1011 -> 1011 ^ (1011 >> 2) -> 1011 ^ 1110 -> 0101
    // 0101 -> 0101 ^ (0101 >> 1) -> 0101 ^ 1010 -> 1111 -> LSB is 1 -> Odd number of 1's

    // 0110 -> 0110 ^ (0110 >> 2) -> 0110 ^ 1101 -> 1011 
    // 1011 -> 1011 ^ (1011 >> 2) -> 1011 ^ 1101 -> 0110 -> LSB is 0 -> Even number of 1's


    // applying folding operation consecutively until the parity bit is 1

    int y = x ^ (x >> 16) ;

    y = y ^ (y >> 8) ;

    y = y ^ (y >> 4) ;

    y = y ^ (y >> 2) ;

    y = y ^ (y >> 1) ;

    // masking the LSB
    return   y  & 0x01 ;
}

int main() {

    unsigned x = 0xFFACDFEE ;

    int val = odd_ones(x) ;

    printf("Is %x odd? ", x) ;
    if(val){
        printf("\n Yes!");
    } else {
        printf("\n No") ;
    }


    return 0 ;
}

