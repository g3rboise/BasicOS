# set magic number to 0x1BADB002 to identified by bootloader 
.set MAGIC,    0x1BADB002
.set FLAGS,    0

# set the checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# set multiboot enabled
.section .multiboot

.long MAGIC
.long FLAGS
.long CHECKSUM


# define the maximum size of stack to 512 bytes
stackBottom:
.skip 1024


# set the stack top which grows from higher to lower
stackTop:
.section .text
.global _start
.type _start, @function

_start:
  # set stack on top
	mov $stackTop, %esp

  # call kernel entry point 
	call kmain
	cli

# end loop
hltLoop:
	hlt
	jmp hltLoop

.size _start, . - _start