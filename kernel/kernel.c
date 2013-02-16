#include "includes/busio.h"
#include "../drivers/screen/includes/screen.h"
#include "../drivers/screen/includes/text.h"

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
    print_char('X', 79, 0, WHITE_ON_BLACK);
    set_cursor_pos(0, 1);
    
    int i;
    for( i = 1; i < 25; i++ ) {
        print("Hello World!\n");
    }
}