#include "vga.h"

/*
* VGA buffer ADDR
*/
uint16_t * vga_buffer = (uint16_t*) VGA_ADDRESS;
uint16_t vga_index;

/*
* vga_entry - compute VGA buffer cell
* @ax : cell value 
*/
uint16_t vga_entry(unsigned char ch, uint8_t fore_color, uint8_t back_color) 
{
  uint16_t ax = 0;
  uint8_t ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

/*
* clear_vga_buffer - reset VGA buffer
*/
void clear_vga_buffer(uint16_t **buffer, uint8_t fore_color, uint8_t back_color)
{
  uint64_t i;
  for(i = 0; i < VGA_BUFFER_SIZE; i++){
    (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
  }
}

/*
* init_vga - init VGA entry
*/
void init_vga(uint8_t fore_color, uint8_t back_color)
{
    vga_index = 0,
    clear_vga_buffer(&vga_buffer, fore_color, back_color);  //clear buffer
}

/*
* print_char - print char on VGA
*/
void print_char(char ch, uint8_t fore_color, uint8_t back_color){
  if(ch =='\n'){
    vga_index = (vga_index / VGA_COLUMN_NBR + 1) * VGA_COLUMN_NBR;
  }
  else if(ch =='\t'){
    vga_index = (vga_index / VGA_TAB_NBR + 1) * VGA_TAB_NBR;
  }
  else{
    vga_buffer[vga_index ++] = vga_entry(ch,fore_color,back_color);
  }
}
