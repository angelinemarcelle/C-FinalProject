# Compiler flags: enforce strict C++11 standard and pedantic error checking
CFLAGS=-pedantic-errors -std=c++11

# Source files for the project
SRC=cardMatch.cpp switchCard.cpp fourtyOne.cpp main.cpp

# Object files generated from source files
OBJ=$(SRC:.cpp=.o)

# Dependency files generated from source files
DEP=$(SRC:.cpp=.d)

# Default target: build the 'main' executable
all: main

# Link object files to create the 'main' executable
main:  cardMatch.o switchCard.o fourtyOne.o main.o
	g++ $(CFLAGS) cardMatch.o switchCard.o fourtyOne.o main.o -o main

# Compile cardMatch.cpp to cardMatch.o
cardMatch.o: cardMatch.cpp cardMatch.h
	g++ $(CFLAGS) -c cardMatch.cpp

# Compile switchCard.cpp to switchCard.o
switchCard.o: switchCard.cpp switchCard.h
	g++ $(CFLAGS) -c switchCard.cpp

# Compile fourtyOne.cpp to fourtyOne.o
fourtyOne.o: fourtyOne.cpp fourtyOne.h
	g++ $(CFLAGS) -c fourtyOne.cpp

# Clean target: remove object files, dependency files, and 'main' executable
clean:
	rm -f cardMatch.o switchCard.o fourtyOne.o main.o main

# Declare 'clean' as a phony target to prevent conflicts with a file named 'clean'
.PHONY: clean
