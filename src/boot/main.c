#include "vga.h"

void kmain(){
    init_vga(WHITE, BLACK);
    print_char('H',WHITE, BLACK);
    print_char('E',WHITE, BLACK);
    print_char('L',WHITE, BLACK);
    print_char('L',WHITE, BLACK);
    print_char('O',WHITE, BLACK);
    print_char(' ',WHITE, BLACK);
    print_char('W',WHITE, BLACK);
    print_char('O',WHITE, BLACK);
    print_char('R',WHITE, BLACK);
    print_char('L',WHITE, BLACK);
    print_char('D',WHITE, BLACK);
    print_char('\n',WHITE, BLACK);
    print_char('A',WHITE, BLACK);
}