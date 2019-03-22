CFLAGS = -Wall -Wextra -std=c11 -O2
OBJS = main.o str.o trie.o list.o valid.o history.o

quantization: $(OBJS)
	gcc -o quantization $(OBJS) $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

str.o: str.c str.h
	gcc -c str.c $(CFLAGS)

trie.o: trie.c trie.h
	gcc -c trie.c $(CFLAGS)

list.o: list.c list.h
	gcc -c list.c $(CFLAGS)

valid.o: valid.c valid.h
	gcc -c valid.c $(CFLAGS)

history.o: history.c history.h
	gcc -c history.c $(CFLAGS)

clean:
	rm *.o
	rm quantization
