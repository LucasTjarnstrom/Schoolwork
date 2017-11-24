# Makefile

# Filkataloger
SOURCE = source

# Kompilator
CCC = g++

# Kompilatorflaggor
CCFLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -I$(SFML_ROOT)/include

#SFML-flaggor
SFMLFLAGS = -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-window -lsfml-system

main: main.o
	$(CCC) main.o -o main $(SFMLFLAGS)

main.o: $(SOURCE)/main.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/main.cc 

clean:
	@ \rm -rf *.o *.gch core

zap: clean
	@ \rm -rf main  *~
