# Makefile

# Filkataloger
SOURCE = source

# Kompilator
CCC = g++

# Kompilatorflaggor
CCFLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -I$(SFML_ROOT)/include

#SFML-flaggor
SFMLFLAGS = -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-window -lsfml-system

# Huvudmål
main: build/main.o
	$(CCC) build/main.o -o main $(SFMLFLAGS)

# Delmål
build/main.o: $(SOURCE)/main.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/main.cc -o build/main.o

.PHONY : clean
clean:
	@ \rm -rf *.o *.gch core
	@ \rm -rf build/*.o build/*.gch build/core

.PHONY : zap
zap: clean
	@ \rm -rf main  *~
	@ \rm -rf build/*~
