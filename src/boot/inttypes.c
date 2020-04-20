 #include "inttypes.h"

const char digit[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
/*
* intergerNbDigit - get length of signed integer macro
*/
inline uint_t intergerNbDigit(int_t i){
    int_t r = i;
    uint_t len = 0;
    if(i < 0)
        len ++;
    while (r != 0)
    {
        r = r / 10;
        len ++;
    }
    return len;
}

/*
* uintergerNbDigit - get length of unsigned integer macro
*/
inline uint_t uintergerNbDigit(uint_t i, uint_t base){
    uint_t len = 0,r = i;
    while (r != 0)
    {
        r = r / base;
        len ++;
    }
    return len;
}

/*
* itoa - convert integer to string 
*/
void itoa(int_t i, char * res){
    uint_t len = intergerNbDigit(i), j = 0;
    int_t r = i;
    if(i < 0 ){
        r *= -1;
    }
    // in case of negative number, res[0] = 0;
    while(j < len){
        res[len - 1 - j] = digit[r % 10];
        j++;
        r = r / 10;  
    }
    if(i < 0 ){
        res[0] = '-';
    }
    res[len] = 0;
}
/*
* uitoa - convert unsigned integer to string to x format
*/
void itoax(uint_t i,  char * res, uint_t base){
    uint_t len = uintergerNbDigit(i,base), j = 0;
    int_t r = i;
    
    while(j < len){
        res[len - 1 - j] = digit[r % base];
        j++;
        r = r / base; 
    }
    res[len] = 0;
}

/*
* uitoa - convert unsigned integer to string 
*/
void uitoa(uint_t i, char * res){
    itoax(i, res,SYSTEM_DEC);
}

/*
* itoah - convert (unsigned) integer to hexa format
*/
void itoah(int_t i, char * res){
    itoax(i, res,SYSTEM_HEX);
}

/*
* itoah - convert (unsigned) integer to binary format 
*/
void itoab(int_t i, char * res){
    itoax(i, res,SYSTEM_BINARY);
}