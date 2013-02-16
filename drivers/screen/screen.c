#include "includes/screen.h"
#include "../../kernel/includes/busio.h"

void set_cursor_pos(short x, short y) {
    int offset = get_screen_offset(x, y);
    
    byte_out(SCREEN_CTRL, CLR_HIGH);
    byte_out(SCREEN_DATA, (unsigned char) ( offset >> 8 ) );
    byte_out(SCREEN_CTRL, CLR_LOW);
    byte_out(SCREEN_DATA, (unsigned char) offset);
}

int get_cursor_pos() {    
    byte_out(SCREEN_CTRL, CLR_HIGH);
    int offset = byte_in(SCREEN_DATA) << 8;
    byte_out(SCREEN_CTRL, CLR_LOW);
    offset += byte_in(SCREEN_DATA);
    
    return offset;
}

int get_screen_offset(short x, short y) {
    return ( (y * MAX_COLS) + x );
}