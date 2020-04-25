CFLAGS = -O3 -Wall -Wdeclaration-after-statement -Wextra

objects = main.o piece.o board.o

main: $(objects)
	gcc -o main $(objects) $(CFLAGS) -lSDL

$(objects): %.o: %.c definitions.h
	gcc -c $< -o $@ $(CFLAGS)
