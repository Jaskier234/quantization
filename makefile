CFLAGS = -Wall -Wextra -std=c11 -O2


quantization: str.o main.o
	gcc -o quantization main.o str.o $(CFLAGS)

str.o: str.c str.h
	gcc -c str.c $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)
