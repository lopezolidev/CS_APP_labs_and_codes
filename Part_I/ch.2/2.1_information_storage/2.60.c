/*
Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1
(most significant). Write code for the following C function, which will return an
unsigned value in which byte i of argument x has been replaced by byte b:

unsigned replace_byte (unsigned x, int i, unsigned char b);

Here are some examples showing how the function should work:

replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB

*/

#include <stdlib.h>
#include <stdio.h>

typedef unsigned char *byte_pointer ;

int is_little_endian() {
    int n = 12345 ;
    // hex representation of n -> an arbitrary number

    byte_pointer n_addr = (byte_pointer) &n ; 
    // storing n memory address in a byte_pointer, 
    // therefore pointing to a single byte of memory of n

    // hex representation of 12345 -> 0x00003039
    // the first byte of 12345 should be 00 if stored as big-endian
    // 39 if little-endian

    if(n_addr[0] & 0x00) {
        return 0 ;
    } // at bit level should be the same
    return 1 ;
    // if they're different its a little-endian machine, because the first byte doesn't match with the actual representation
}


unsigned replace_byte (unsigned x, int i, unsigned char b){
    
    // first we have to find out if the current machine is little-endian or big-endian
    int endiannes = is_little_endian() ;

    unsigned result = 0x0;

    byte_pointer address = (byte_pointer) &x ;

    // clause guard to make sure we're not trying to change a number over the quantity of bytes we have
    if (i == sizeof(x)){
        printf("Error! You're over bounds. \n") ;
        return -1 ;
    }

    if (endiannes == 1){
    // the machine is little endian, we need to traverse in ascending order

    int j = 0 ;
        while(j < sizeof(x)) {

            if(j == i) {
            // we're in the address of the byte we want to alter

            address[j] = b ; 
            return x ;
            }
            j++ ;
        }
    } else {
        // case of a big-endian machine, we must traverse the byte sequence backwards
        // starting from the highest address, meaning the address of the least significance

        int j = sizeof(x) - 1 ;
        int k = 0 ;
        // this counter allows us to know the significance of the byte we're stepping on

        while(j > 0) {
            if(k == i) {

                address[j] = b ;
                return x ;

            } // when the counter and index of byte to change match, we'll change the number

            k++ ;
            j-- ;
        }

    }

}


int main() {

    unsigned x = 0x12345678 ;
    unsigned char b = 0xAB ;

    unsigned int n = replace_byte(x, 4, b) ;
    // replace_byte(x, 2, b) ;

    if(n != ~0x00){
        printf("%x", n) ;
    } // printing without errors

    return 0 ;
}