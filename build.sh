cd boot/
nasm boot_sect.asm -f bin -o boot_sect.bin
nasm kernel_ent.asm -f elf -o kernel_ent.o

cd ../kernel/ 

gcc -m32 -ffreestanding -c kernel.c busio.c
ld -m elf_i386 -o kernel.bin -Ttext 0x1000 ../boot/kernel_ent.o busio.o kernel.o --oformat binary

cd ..
cat boot/boot_sect.bin kernel/kernel.bin > os-image.bin

