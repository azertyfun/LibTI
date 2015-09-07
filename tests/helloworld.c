#include "../src/libti.c" //I'd include the actual header file if sdcc handled multiple source files... Until then multiple source files will become one like this

void main() {
    clearscreen(); //If you don't clear the lcd first, you'll have some nice artifacts but no text.

    println("Hello, world !");

    getKey();
}
