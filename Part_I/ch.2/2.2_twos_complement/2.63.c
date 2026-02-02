#include <stdlib.h>
#include <stdio.h>

typedef unsigned char *byte_pointer ;

unsigned srl(unsigned x, int k) {
    /*Perform shift arithmetically*/
    unsigned xsra = (int) x >> k ;

    // if k = 3

    unsigned mask = ~0x00 ;
    // 0xFFFFFFFF

    int size_of_left_shift = (sizeof(x) << 3) - k ;
    // (4 * 2³) - 3 = 29

    unsigned shifted_and_complemented_mask = ~(mask << size_of_left_shift) ;
    // ~(0xFFFFFFFF * 2^(29))= ~(e0000000) = 0x1FFFFFFF <- ready to mask the real number

    unsigned result = xsra & shifted_and_complemented_mask ;

    return result ;
}



int sra(int x, int k) {
    /*Perform shift logically*/
    int xsrl = (unsigned) x >> k ;


    unsigned mask = ~0x00 ;
    // 0xFFFFFFFF

    unsigned left_shift_value = ((sizeof(x) << 3) - k) ;

    //isolating sign bit
    unsigned MSB_index = (sizeof(x) << 3) - 1 ;

    // shifting and finding MSB
    unsigned MSB = x & (0x01 << MSB_index) ;

    mask =  ~0x00  +  !MSB ;
    // will be 0x00000000 if MSB is 0, will be 0x7FFFFFFF if its 1. 

    mask = mask << left_shift_value ;

    int result = mask | xsrl ;

    return result ;
}

int main() {

    unsigned x = 0xA0393039 ;

    unsigned res = srl(x, 5) ;

    printf("X: 0xA0393039, srl result: %d \n", res) ;

    int sra_res = sra(x, 5) ;

    printf("X: 0xA0393039, sra result: %d \n", sra_res) ;


    return 0 ;
}