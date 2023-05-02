CFLAGS=-pedantic-errors -std=c++11
SRC=cardMatch.cpp fourtyOne.cpp main.cpp switchCard.cpp
OBJ=$(SRC:.cpp=.o)

all: main

main: cardmatch.o fourtyOne.o switchCard.o main.o
	g++ $(CFLAGS) $(OBJ) -o main

%.o: %.cpp
	g++ $(CFLAGS) $< -o $@

clean:
	rm -f main $(OBJ)
  
.PHONY: clean
