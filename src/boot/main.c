#include "vga.h"

void kmain(){
    uint_t val = 16;
    init_vga(WHITE, BLACK);

    print_string("value \"",WHITE,BLACK);
    print_int(val,WHITE,BLACK);
    print_string("\" on :\n",WHITE,BLACK);
    print_string("- hex : ",WHITE,BLACK);
    print_int_hex(val,WHITE,BLACK);
    print_string("\n- bin : ",WHITE,BLACK);
    print_int_bin(val,WHITE,BLACK);
}

