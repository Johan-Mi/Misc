CFLAGS = -std=c++2a -g -Wall -fconcepts

main: main.o mos6502.o
	g++ $(CFLAGS) -o main main.o mos6502.o

main.o: main.cpp mos6502.hpp
	g++ $(CFLAGS) -c main.cpp

mos6502.o: mos6502.cpp mos6502.hpp
	g++ $(CFLAGS) -c mos6502.cpp

clean:
	rm -r *.o main
