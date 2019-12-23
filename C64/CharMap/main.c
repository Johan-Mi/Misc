#include <stdlib.h>
#include <conio.h>

int main(void) {
	char i = 0;
	do {
		cputc(i++);
	} while(i);

	return EXIT_SUCCESS;
}
