# Makefile

# Filkataloger
SOURCE = source

# Kompilator
CCC = g++

# Kompilatorflaggor
CCFLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Weffc++ -I$(SFML_ROOT)/include

#SFML-flaggor
SFMLFLAGS = -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-window -lsfml-system

#Objektmoduler
OBJECTS = build/main.o build/Drawable.o build/Character.o build/Player.o build/Button.o build/Level.o build/Game.o build/Start_Menu.o

# Huvudmål
main: $(OBJECTS)
	$(CCC) build/main.o build/Drawable.o build/Character.o build/Player.o build/Button.o build/Game.o build/Start_Menu.o -o main $(SFMLFLAGS)

# Delmål
build/main.o: $(SOURCE)/main.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/main.cc -o build/main.o

build/Player.o : $(SOURCE)/Player.h $(SOURCE)/Player.cc $(SOURCE)/Character.h $(SOURCE)/Character.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Player.cc -o build/Player.o

build/Button.o : $(SOURCE)/Button.h $(SOURCE)/Button.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Button.cc -o build/Button.o

build/Character.o : $(SOURCE)/Character.h $(SOURCE)/Character.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Character.cc -o build/Character.o

build/Drawable.o : $(SOURCE)/Drawable.h $(SOURCE)/Drawable.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Drawable.cc -o build/Drawable.o

build/Level.o : $(SOURCE)/Level.h $(SOURCE)/Level.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Level.cc -o build/Level.o

build/Game.o : $(SOURCE)/Game.h $(SOURCE)/Game.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Game.cc -o build/Game.o

build/Start_Menu.o : $(SOURCE)/Start_Menu.h $(SOURCE)/Start_Menu.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Start_Menu.cc -o build/Start_Menu.o

.PHONY : clean
clean:
	@ \rm -rf *.o *.gch core
	@ \rm -rf build/*.o build/*.gch build/core

.PHONY : zap
zap: clean
	@ \rm -rf main  *~
	@ \rm -rf build/*~
