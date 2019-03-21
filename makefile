CFLAGS = -Wall -Wextra -std=c11 -g #-O2
OBJS = main.o str.o vector.o trie.o list.o

quantization: $(OBJS)
	gcc -o quantization $(OBJS) $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

str.o: str.c str.h
	gcc -c str.c $(CFLAGS)

vector.o: vector.c vector.h
	gcc -c vector.c $(CFLAGS)

trie.o: trie.c trie.h
	gcc -c trie.c $(CFLAGS)

list.o: list.c list.h
	gcc -c list.c $(CFLAGS)

clean:
	rm *.o
	rm quantization
