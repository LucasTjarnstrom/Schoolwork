# Makefile

# Filkataloger
SOURCE = source
TESTFILES = test-files

# Kompilator
CCC = g++

# Kompilatorflaggor
CCFLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++ -I$(SFML_ROOT)/include

#SFML-flaggor
SFMLFLAGS = -L$(SFML_ROOT)/lib -lsfml-graphics -lsfml-window -lsfml-system

# Huvudmål
player-test: $(TESTFILES)/test_main.o $(TESTFILES)/Player.o $(TESTFILES)/Character.o $(TESTFILES)/Drawable.o $(TESTFILES)/player-test.cc
	$(CCC) $(CCFLAGS) $(TESTFILES)/test_main.o $(TESTFILES)/Player.o $(TESTFILES)/Character.o $(TESTFILES)/Drawable.o $(TESTFILES)/player-test.cc -o player-test $(SFMLFLAGS)

# Delmål
test_main.o: $(TESTFILES)/test_main.cc
	$(CCC) $(CCFLAGS) -c $(TESTFILES)/test_main.cc -o $(TESTFILES)/test_main.o

$(TESTFILES)/Player.o : Player.h Player.cc Character.h Character.cc
	$(CCC) $(CCFLAGS) -c Player.cc -o $(TESTFILES)/Player.o

$(TESTFILES)/Character.o : Character.h Character.cc
	$(CCC) $(CCFLAGS) -c Character.cc -o $(TESTFILES)/Character.o

$(TESTFILES)/Drawable.o : Drawable.h Drawable.cc
	$(CCC) $(CCFLAGS) -c Drawable.cc -o $(TESTFILES)/Drawable.o

.PHONY : clean
clean:
	@ \rm -rf *.o *.gch core
	@ \rm -rf $(TESTFILES)/*.o $(TESTFILES)/*.gch $(TESTFILES)/core

.PHONY : zap
zap: clean
	@ \rm -rf player-test *~
	@ \rm -rf $(TESTFILES)/*~
