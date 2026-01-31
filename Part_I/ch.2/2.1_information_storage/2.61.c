#include <stdio.h>
#include <stdlib.h>

int main() {

    int x = 12345;


    int shift_val = (sizeof(x) -1) << 3 ;

    int xright = x >> shift_val ;

    int result = xright & 0xFF ;

    printf("%.2x", result ) ;

    return 0 ;
}