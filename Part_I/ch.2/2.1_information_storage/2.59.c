/*
Write a C expression that will yield a word consisting of the least significant byte of x and the
remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, this would give 0x765432EF.
*/

#include <stdlib.h>
#include <stdio.h>

int yOverX(int x, int y) {
    x = x & 0xFF ;
    // masking the least significant byte

    y = y & ~0xFF ;
    // obtaining all but the least significant byte of y

    return y | x ;
    // to set the least significant byte of y in x 
}
// independent of the word size

int main() {
    int hex_masked = 0x0;

    int x = 0x89ABCDEF ;
    int y = 0x76543210 ;

    hex_masked = yOverX(x, y) ;

    printf("%.2x", hex_masked) ;
}