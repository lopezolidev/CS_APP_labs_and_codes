#include <stdlib.h>
#include <stdio.h>

int int_shifts_are_arithmetic(int x){

    // size of x-8
    int shiftSize = (sizeof(x) - 1) << 3 ;

    // shifting x , w-8 bits
    int shiftedX = x >> shiftSize ;

    // taking the right left byte of the MSB of x
    int significantByte = x & 0xFF00 ;

    // with arithmetic right shift, this byte is all 1's, if not all 0's
    return significantByte && 0x01 ;

}

int main() {

    int n = ~0x00 ;

    int res = int_shifts_are_arithmetic(n) ;

    printf("Int shifts are arithmetic: %d", res) ;
    printf("\n") ;

    return 0 ;
}