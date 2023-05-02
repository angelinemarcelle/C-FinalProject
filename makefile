CFLAGS=-pedantic-errors -std=c++11
SRC=cardMatch.cpp switchCard.cpp fourtyOne.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: main

main:  cardMatch.o switchCard.o fourtyOne.o main.o
	g++ $(CFLAGS) cardMatch.o switchCard.o fourtyOne.o main.o -o main

cardMatch.o: cardMatch.cpp cardMatch.h
	g++ $(CFLAGS) -c cardMatch.cpp

switchCard.o: switchCard.cpp switchCard.h
	g++ $(CFLAGS) -c switchCard.cpp

fourtyOne.o: fourtyOne.cpp fourtyOne.h
	g++ $(CFLAGS) -c fourtyOne.cpp

clean:
	rm -f cardMatch.o switchCard.o fourtyOne.o main.o main
  
.PHONY: clean
