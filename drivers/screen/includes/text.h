#ifndef __TEXT_H
#define __TEXT_H

void print_char(char c, short col, short row, char attrib_byte);
void print_at(char* string, short col, short row);
void print(char* string);

int scroll(int cursor);

#endif