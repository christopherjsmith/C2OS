#!/bin/bash
#
# ld seems to not work on Mac as expected
#

DIRECTORY=release
if [ ! -d "$DIRECTORY" ]; then
    mkdir $DIRECTORY
fi

cd boot/
nasm boot_sect.asm -f bin -o ../release/boot_sect_osx.bin
nasm kernel_ent.asm -f elf -o ../release/kernel_ent_osx.o

cd ../kernel/ 

gcc -Wall -O3 -m32 -ffreestanding -fno-PIC kernel.c -S -o ../release/kernel_osx.o
gcc -Wall -O3 -m32 -ffreestanding -fno-PIC busio.c -S -o ../release/busio_osx.o

cd ..
cat release/boot_sect_osx.bin release/kernel_osx.o > os-image.bin