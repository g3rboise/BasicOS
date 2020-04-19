#ifndef _VGA_H_
#define _VGA_H_
    #include "inttypes.h"
    
    #define NULL 0
    #define VGA_ADDRESS 0xB8000
    #define VGA_COLUMN_NBR 80
    #define VGA_LINE_NBR 25
    #define VGA_TAB_NBR 4
    #define VGA_BUFFER_SIZE VGA_COLUMN_NBR * VGA_LINE_NBR

    void print_char(char ch, uint8_t fore_color, uint8_t back_color);
    void init_vga(uint8_t fore_color, uint8_t back_color);

    enum vga_color {
        BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        GREY,
        DARK_GREY,
        BRIGHT_BLUE,
        BRIGHT_GREEN,
        BRIGHT_CYAN,
        BRIGHT_RED,
        BRIGHT_MAGENTA,
        YELLOW,
        WHITE,
    };
#endif