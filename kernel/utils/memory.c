#include "includes/memory.h"

void memcopy(char* src, char* dst, int numberOfBytes) {
    for( ; numberOfBytes > 0; numberOfBytes--) {
        *(dst++) = *(src++);
    }
}