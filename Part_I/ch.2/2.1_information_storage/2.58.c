/* 
Write a procedure is_little_endian that will return 1 when compiled and run 
on a little-endian machine, and will return 0 when compiled and run on a big-endian
machine. This program should run on any machine, regardless of its word size
*/

#include <stdio.h>
#include <stdlib.h>

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

int main() {
    // calling procedure of little- or big-endian

    if(is_little_endian()){
        printf("little-endian machine") ;
        return 0 ;
    }
    printf("big-endian machine") ;
    return 0;
}