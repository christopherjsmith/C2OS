cd boot/
nasm boot_sect.asm -f bin -o boot_sect.bin

cd ../kernel/
gcc -ffreestanding -c kernel.c -o kernel.o
ld -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary

cd ..
cat boot/boot_sect.bin kernel/kernel.bin > os-image.bin

