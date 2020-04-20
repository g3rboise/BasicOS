#include "vga.h"

void kmain(){
    init_vga(WHITE, BLACK);
    print_string("Hello world !\n",WHITE,BLACK);
    print_int(-135,WHITE,BLACK);
}

