#!/bin/bash

DIRECTORY=release/linux
if [ ! -d "$DIRECTORY" ]; then
    mkdir -p $DIRECTORY
fi

cd boot/
nasm boot_sect.asm -f bin -o ../$DIRECTORY/boot_sect.bin
nasm kernel_ent.asm -f elf -o ../$DIRECTORY/kernel_ent.o

cd ../$DIRECTORY

gcc -Wall -m32 -ffreestanding -c ../../kernel/kernel.c ../../kernel/busio.c
ld -m elf_i386 -o kernel.bin -Ttext 0x1000 kernel_ent.o busio.o kernel.o --oformat binary

cd ../../
cat $DIRECTORY/boot_sect.bin $DIRECTORY/kernel.bin > os-image.bin

echo "--- Build Complete ---"
echo "launching bochs..."
bochs -q
echo "Done, cleaning up..."
rm -rf release
find ./ -name "*.bin" | xargs rm -Rf
find ./ -name "*.o" | xargs rm -Rf
echo "Cleaned up."