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
OBJECTS = build/main.o build/Drawable.o build/Character.o build/Player.o build/Button.o build/Level.o build/Game.o build/Start_Menu.o build/Environment.o build/Floor.o build/Wall.o build/Ceiling.o build/Map.o build/Collision.o build/High_Score_List.o build/Enemy.o build/Attack.o build/Player_Attack.o build/Goal.o

# Huvudmål
main: $(OBJECTS)
	$(CCC) build/main.o build/Drawable.o build/Character.o build/Player.o build/Button.o build/Game.o build/Start_Menu.o build/Environment.o build/Floor.o build/Wall.o build/Ceiling.o build/Map.o build/Collision.o build/High_Score_List.o build/Enemy.o build/Attack.o build/Player_Attack.o build/Goal.o -o main $(SFMLFLAGS)

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

build/Environment.o : $(SOURCE)/Environment.h $(SOURCE)/Environment.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Environment.cc -o build/Environment.o

build/Floor.o : $(SOURCE)/Floor.h $(SOURCE)/Floor.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Floor.cc -o build/Floor.o

build/Wall.o : $(SOURCE)/Wall.h $(SOURCE)/Wall.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Wall.cc -o build/Wall.o

build/Ceiling.o : $(SOURCE)/Ceiling.h $(SOURCE)/Ceiling.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Ceiling.cc -o build/Ceiling.o

build/Map.o : $(SOURCE)/Map.h $(SOURCE)/Map.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Map.cc -o build/Map.o

build/Collision.o : $(SOURCE)/Collision.h $(SOURCE)/Collision.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Collision.cc -o build/Collision.o

build/High_Score_List.o : $(SOURCE)/High_Score_List.h $(SOURCE)/High_Score_List.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/High_Score_List.cc -o build/High_Score_List.o

build/Enemy.o : $(SOURCE)/Enemy.h $(SOURCE)/Enemy.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Enemy.cc -o build/Enemy.o

build/Attack.o : $(SOURCE)/Attack.h $(SOURCE)/Attack.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Attack.cc -o build/Attack.o

build/Player_Attack.o : $(SOURCE)/Player_Attack.h $(SOURCE)/Player_Attack.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Player_Attack.cc -o build/Player_Attack.o

build/Goal.o : $(SOURCE)/Goal.h $(SOURCE)/Goal.cc
	$(CCC) $(CCFLAGS) -c $(SOURCE)/Goal.cc -o build/Goal.o

.PHONY : clean
clean:
	@ \rm -rf *.o *.gch core
	@ \rm -rf build/*.o build/*.gch build/core

.PHONY : zap
zap: clean
	@ \rm -rf main  *~
	@ \rm -rf build/*~
