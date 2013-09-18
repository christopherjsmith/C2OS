#include "../drivers/screen/includes/text.h"

void main() {    
    clear_screen();
    
    println("Welcome to C20S");
    println("---------------");
    
    println("");
    
    println("Screen drivers for VGA Text Mode are now written");
    println("  and scrolling works!");
    
    println("");
    
    println("Regards, Chris!");
    
    println("");
    println("");
    println("OK. So Development has begun again! WOO!");
    println("I don't know how much we will get done, but lets aim to get something new working.");
    println("... I still have no ideas what I am going to work on from here :(");
    
    setBackground( (char) 0x10 );
    
    char b[33];
   
    b[0] = 218;
    int i = 1;
    
    for( i = i; i < 31; i++ ) {
		b[i] = 196;
	}
    
    b[31] = 191;
    b[32] = 0;
    print(b);
    println("");
    
    b[0] = 179;
    
    for( i = 1; i < 31; i++ ) {
		b[i] = ' ';
	}
    
    b[31] = 179;
    b[32] = 0;
    
    print(b);
    
    setBackground( (char) 0x10 );
    
    //unsigned char* p = 0xa0000;
    
    //int i = 0;
    
    //for( i = 0; i < 320*200; i++ ) {
    //        p[i] = 1; // blue pixel
	//	}
}
