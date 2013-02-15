#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0F

void main() {
	char* video_mem = (char*) 0xb8000;

	int x = 0;
	int y = 0;

	for(x = 0; x < MAX_COLS * MAX_ROWS * 2; x += 2) {
		*(video_mem + x) = ' ';
		*(video_mem + x +1) = 0x0F;
	}

	*(video_mem) = 'X';
	*(video_mem+1) = WHITE_ON_BLACK;
}
