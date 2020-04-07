CFLAGS = -O3 -Wall

objects = main.o piece.o board.o

main: $(objects)
	gcc -o main $(objects) $(CFLAGS) -lSDL

$(objects): %.o: %.c
	gcc -c $< -o $@ $(CFLAGS)
