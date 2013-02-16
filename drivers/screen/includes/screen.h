#ifndef __SCREEN_H
#define __SCREEN_H

#define MAX_ROWS 25
#define MAX_COLS 80

#define VIDEO_MEMORY 0xB8000

#define SCREEN_CTRL 0x3D4
#define SCREEN_DATA 0x3D5
#define CLR_HIGH 0x0E
#define CLR_LOW 0x0F

#define WHITE_ON_BLACK 0x0F

void set_cursor_pos(short x, short y);
int get_cursor_pos();

int get_screen_offset(short x, short y);

#endif