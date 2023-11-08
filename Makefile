all: bin/make_deck bin/shuffle_deck

bin/make_deck:  obj/util.o obj/card.o obj/deck.o  obj/make_deck.o
	gcc -o bin/make_deck  obj/util.o  obj/card.o obj/deck.o obj/make_deck.o

bin/shuffle_deck:  obj/util.o obj/card.o obj/deck.o  obj/shuffle_deck.o
	gcc -o bin/shuffle_deck  obj/util.o  obj/card.o obj/deck.o obj/shuffle_deck.o

obj/util.o: src/util.c include/util.h
	gcc -c -g src/util.c -o obj/util.o

obj/card.o: src/card.c include/card.h
	gcc -c -g src/card.c -o obj/card.o

obj/deck.o: src/deck.c include/deck.h
	gcc -c -g src/deck.c -o obj/deck.o

obj/make_deck.o: src/make_deck.c
	gcc -c -g src/make_deck.c -o obj/make_deck.o

obj/shuffle_deck.o: src/shuffle_deck.c
	gcc -c -g src/shuffle_deck.c -o obj/shuffle_deck.o

clean:
	rm bin/* obj/*
