#ifndef _INTTYPES_H_
#define _INTTYPES_H_
    #define _32_BITS

    typedef char int8_t;
    typedef short int16_t;
    typedef int int32_t;

    typedef unsigned char uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int uint32_t;

    #ifdef _64_BITS
        typedef long int64_t;
        typedef unsigned long uint64_t;

        typedef uint64_t uint_t ;
        typedef int64_t int_t ;
    #endif

    #ifdef _32_BITS
        typedef uint32_t uint_t ;
        typedef int32_t int_t ;
    #endif

    void itoa(int_t i, char * res);
    void uitoa(uint_t i, char * res);

#endif