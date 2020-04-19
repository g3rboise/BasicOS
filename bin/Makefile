ISO=BasicOs.iso
BINARY=BasicOs.bin

# create iso image with kernel and grub
${ISO} : BasicOs.bin
	mkdir -p isodir/boot/grub
	cp BasicOs.bin isodir/boot/${BINARY}
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

#create kernel binary
${BINARY}: main.o boot.o linker.ld
	ld -m elf_i386 -T linker.ld main.o boot.o -o $@ -nostdlib

main.o : ../src/boot/main.c
	gcc -m32 -c ../src/boot/main.c -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o : 
	as --32  ../src/boot/boot.s -o boot.o

#clear bin folder
clear :
	rm *.o
	rm BasicOs.*
	rm -rf isodir

#run iso on qemu
run : ${ISO}
	qemu-system-x86_64 -cdrom ${ISO}
