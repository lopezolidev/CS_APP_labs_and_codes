#include <stdlib.h>
#include <stdio.h>

typedef unsigned char *byte_pointer ;

unsigned srl(unsigned x, int k) {
    /*Perform shift arithmetically*/
    unsigned xsra = (int) x >> k ;

    unsigned mask = ~0x00 ;

    byte_pointer ptr = (byte_pointer) &mask ;

    




    printf("%x", mask) ;

}



int sra(int x, int k) {
    /*Perform shift logically*/
    int xsrl = (unsigned) x >> k ;
}

int main() {

    unsigned x = ~0x00 ;

    unsigned res = srl(x, 3) ;

    


    return 0 ;
}