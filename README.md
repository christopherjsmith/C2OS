C2OS
====
### Table of Contents
* Table of Contents
* 1 Tools and the toolchain
* 2 Build process
* 3 Roadmap
* 4 TODOs
* 5 Known Bugs

### 1 Tools and the toolchain
This section list the tools you will need to build and run this project. Assuming you will be running using an emulator. You are free to user other emulators, although only those listed will have the running information, it will be down to you to figure out how to build or run with different tools. If you do use different tools please update this to reflect the information you have found.

* NASM
* GCC
* make
* ld
* bochs (or QEmu)
* Text Editor or IDE of your choice


### 2 Build process
This section describes how to build the current source code. This should be updated whenever the build prcoess changes. In the next revisions we should look at implementing *make scripts* which will allow the build process to stay fixed. In the mean time this will do.

cd boot/
nasm boot_sect.asm -f bin -o boot_sect.bin
nasm kernel_ent.asm -f elf -o kernel_ent.o

    cd ../kernel/ 

    gcc -m32 -ffreestanding -c kernel.c busio.c
    ld -m elf_i386 -o kernel.bin -Ttext 0x1000 ../boot/kernel_ent.o busio.o kernel.o --oformat binary

    cd ..
    cat boot/boot_sect.bin kernel/kernel.bin > os-image.bin

or see the added build script in root dir

    ./build.sh

if you get permission denied run

    chmod +x ./build.sh
    ./build.sh

Run as follows:

    bochs -q

or with QEmu

    qemu os-image.bin

### 3 Roadmap

1. Complete Bootloader for BootManager 
2. BootManager to launch different OSs
3. PANIC ;)


### 4 TODOs
These are in no particular order, if we wish to prioritise, they will be made bold to highlight a more urgent need for completion.

* **Update build process to make**
* Complete bootloader to load BootManager
* Implement BootManager
* Complete Screen Driver for 32-Bit PM

### 5 Known Bugs
