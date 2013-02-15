#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0F
#define VIDEO_MEMORY 0xB8000

#define CTRL 0x3D4
#define DATA 0x3D5

#include "include/busio.h"

void printX() {
    unsigned char* video_mem = (unsigned char*) VIDEO_MEMORY;
    *video_mem = 'X';
}

void main() {
    unsigned char* video_mem = (unsigned char*) VIDEO_MEMORY;

    int x = 0;

    //for(x = 0; x <= (MAX_COLS * MAX_ROWS); x++) {
    //    *(video_mem++) = ' ';
    //    *(video_mem++) = WHITE_ON_BLACK;
    //}
    
    for(x = 0; x <= (MAX_COLS * MAX_ROWS * 2); x += 2) {
            *( video_mem+((short)(x  )) ) = ' ';
            *( video_mem+((short)(x+1)) ) = WHITE_ON_BLACK;
    }
    
    printX();
    
    byte_out(CTRL, 14);
    byte_out(DATA, 0x00);
    byte_out(CTRL, 15);
    byte_out(DATA, 0x00);
}