#include <peekpoke.h>
#include <stdlib.h>

int main(void) {
    char i = 0;
    while (1) {
        POKE(53280L, i++);
    }

    return EXIT_SUCCESS;
}
