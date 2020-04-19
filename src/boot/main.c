#include "vga.h"

void kmain(){
    init_vga(WHITE, BLACK);
    print_string("Hello world !",WHITE,BLACK);
}