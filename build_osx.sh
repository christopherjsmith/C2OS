#!/bin/bash

# ld seems to not work on Mac as expected
#

DIRECTORY=release
if [ ! -d "$DIRECTORY" ]; then
    mkdir -p $DIRECTORY/{osx,linux}
fi

cd boot/
nasm boot_sect.asm -f bin -o ../release/osx/boot_sect.o
nasm kernel_ent.asm -f elf -o ../release/osx/kernel_ent.o

cd ../kernel/ 

gcc -Wall -O3 -m32 -ffreestanding -fno-PIC kernel.c -S -o ../release/osx/kernel.o
gcc -Wall -O3 -m32 -ffreestanding -fno-PIC busio.c -S -o ../release/osx/busio.o
ld -o linked.bin -e start ../release/osx/boot_sect.o \
	../release/osx/kernel_ent.o ../release/osx/kernel.o ../release/osx/busio.o \
		-macosx_version_min 10.5 -arch i386

cd ..
cat release/osx/boot_sect.bin release/osx/kernel.o > os-image.bin

# echo "--- Build Complete ---"
# echo "launching bochs..."
# bochs -q
# echo "Done, cleaning up..."
# rm -rf release
# find ./ -name "*.bin" | xargs rm -Rf
# find ./ -name "*.o" | xargs rm -Rf
# echo "Cleaned up."