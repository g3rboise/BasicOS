ISO=BasicOs.iso
BINARY=BasicOs.bin

GRUB_CONF=grub.cfg
LINKER_CONF=linker.ld

SRC_DIR   = ../src/boot/
OBJ_DIR   = ./obj/

SRC_C  := $(wildcard $(SRC_DIR)/*.c)
SRC_S  := $(wildcard $(SRC_DIR)/*.s)
OBJ_C  := $(SRC_C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_S  := $(SRC_S:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

# create iso image with kernel and grub
$(ISO) : $(BINARY)
	@mkdir -p isodir/boot/grub
	@cp BasicOs.bin isodir/boot/$(BINARY)
	@cp $(GRUB_CONF) isodir/boot/grub/$(GRUB_CONF)
	@grub-mkrescue -o $@ isodir

#create kernel binary
$(BINARY): $(OBJ_C) $(OBJ_S) $(LINKER_CONF)
	@ld -m elf_i386 -T $(LINKER_CONF) $(OBJ_C) $(OBJ_S) -o $@ -nostdlib

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -m32 -c $^ -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@as --32  -c $^ -o $@

#clear bin folder
clear :
	rm -rf $(OBJ_DIR)
	rm BasicOs.*
	rm -rf isodir

#run iso on qemu
run : ${ISO}
	qemu-system-x86_64 -cdrom ${ISO}
