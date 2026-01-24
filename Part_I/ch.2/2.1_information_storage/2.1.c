#include <stdio.h>

typedef unsigned char *byte_pointer ;

void show_bytes(byte_pointer start, size_t len) {
    int i ;
    for (i = 0 ; i < len ; i++) {
        printf(" %.2x", start[i]) ;
    printf(" ") ;
    }
    printf("\n") ;
    printf("-----------------------");
    printf("\n") ;
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)) ;
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)) ;
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)) ;
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short)) ;
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long)) ;
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double)) ;
}

void test_show_bytes(int val) {
    int ival = val ;
    float fval = (float) ival ;
    int *pval = &ival ;
    short sval = (short) ival ;
    long lval = (long) ival ;
    double dval = (double) ival ;

    printf("Int: ") ;
    show_int(ival) ;
    printf("\n") ;

    printf("Float: ") ;
    show_float(fval) ;
    printf("\n") ;

    printf("Pointer: ") ;
    show_pointer(pval) ;
    printf("\n") ;

    printf("Short: ") ;
    show_short(sval) ;
    printf("\n") ;

    printf("Long: ") ;
    show_long(lval) ;
    printf("\n") ;

    printf("Double: ") ;
    show_double(dval) ;
    printf("\n") ;
 
}

int main() {
// this machine is little endian
    int i = 12345 ;

    test_show_bytes(i) ;

    return 0 ;
}