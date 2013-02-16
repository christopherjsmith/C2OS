#include "includes/screen.h"
#include "includes/text.h"
#include "../../kernel/includes/busio.h"
#include "../../kernel/utils/includes/memory.h"

void print_char(char c, short col, short row, char attrib_byte) {
    unsigned char* vmem = (unsigned char*) VIDEO_MEMORY;
    
    if( !attrib_byte ) {
        attrib_byte = WHITE_ON_BLACK;
    }
    
    int offset = 0;
    
    if( col >= 0 && row >= 0 ) {
        offset = get_screen_offset( col, row ) * 2;
    } else {
        offset = get_cursor_pos() * 2;
    }

    if( c == '\n' ) {
        offset = get_screen_offset( 79, (short)( (offset/2) / MAX_COLS ) ) * 2;
    } else {
        vmem[ offset ] = c;
        vmem[ offset + 1 ] = attrib_byte;
    }
    
    offset += 2;
    
    offset = scroll(offset);
    
    set_cursor_pos( (short)( (offset/2) % MAX_COLS), (short)( (offset/2) / MAX_COLS) );
}

void print_at(char* string, short col, short row) {
    int i = 0;
    
    if( col < 0 && row < 0 ) {
        int offset = get_cursor_pos();
        
        col = offset % MAX_COLS;
        row = offset / MAX_COLS;
    }
    
    for( i = 0; string[i] != 0; i++) {
        print_char( string[i], col + i, row, WHITE_ON_BLACK );
    }
}

void print(char* string) {
    print_at(string, -1, -1);
}

int scroll(int cursor) {
    if( cursor > (MAX_COLS * MAX_ROWS * 2) ) {
        memcopy((char*)(VIDEO_MEMORY + (MAX_COLS * 2)), (char*)VIDEO_MEMORY, MAX_COLS*(MAX_ROWS-1)*2);
        
        cursor -= MAX_COLS*2;
        
        int i;
        for(i = 0; i < MAX_COLS; i++) {
            print_char(' ', i, MAX_ROWS-1, WHITE_ON_BLACK);
        }
    }
    
    return cursor;
}