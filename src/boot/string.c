
#include "inttypes.h"

/*
* strlen - length of string
*/
uint64_t strlen(char * str){
    uint64_t len = 0;
    while (str[len] != 0)
        len ++;
    return len;
}
