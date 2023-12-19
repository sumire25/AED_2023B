all: main.o math.o
	g++ main.o math.o -o pruebaBibliotecas
main.o: main.c math.h
	g++ -c main.c
math.o: math.c math.h
	g++ -c math.c
clear:
	rm pruebaBibliotecas
	rm main.o
	rm math.o
