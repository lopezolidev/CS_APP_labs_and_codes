#include <stdio.h>
#include <stdlib.h>

int A(int x){
    /*Any bit of x equals 1*/

    printf("X in A: %.2x", x) ;
    printf("\n") ;

    return !~x ;
}

int B(int x){
    /*Any bit of x equals 0*/

    return !x;
}

int C(int x) {
    /*Any bit in the least significant byte of x equals 1*/

    int LSB = x & 0xFF ;

    return !!LSB ;
}

int D(int x) {
    /*Any bit in the most significant byte of x equals 0*/

    // shifting w-8
    int shiftSize = (sizeof(x) -1) << 3 ;

    // MSB in LSB position
    int shiftedX = x >> shiftSize ;
    
    // if any bit of the MSB equals 0, then !0x00 == 0x01 
    return !(shiftedX & 0xFF) ;

}

int main() {

    int x = ~0x00; // ->0x FF FF FF FF


    int res = A(x) ;
    printf("x: ~0x00, A: %d", res) ;
    printf("\n") ;

    res = B(x) ;
    printf("x: ~0x00, B: %d", res) ;
    printf("\n") ;

    res = C(x) ;
    printf("x: ~0x00, C: %d", res) ;
    printf("\n") ;

    res = D(x) ;
    printf("x: ~0x00, D: %d", res) ;
    printf("\n") ;

    return 0 ;
}