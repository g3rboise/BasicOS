
#include "inttypes.h"

/*
* strlen - length of string
*/
uint_t strlen(char * str){
    uint_t len = 0;
    while (str[len] != 0)
        len ++;
    return len;
} 
