# Makefile

# Filkataloger
SOURCE = source
TESTFILES = test-files

# Kompilator
CCC = g++

# Kompilatorflaggor
CCFLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++

# Huvudmål
player-test: $(TESTFILES)/test_main.o $(TESTFILES)/Player.o $(TESTFILES)/player-test.cc
	$(CCC) $(CCFLAGS) $(TESTFILES)/test_main.o $(TESTFILES)/Player.o $(TESTFILES)/player-test.cc -o player-test

# Delmål
test_main.o: $(TESTFILES)/test_main.cc
	$(CCC) $(CCFLAGS) -c $(TESTFILES)/test_main.cc -o $(TESTFILES)/test_main.o

$(TESTFILES)/Player.o : Player.h Player.cc
	$(CCC) $(CCFLAGS) -c Player.cc -o $(TESTFILES)/Player.o

.PHONY : clean
clean:
	@ \rm -rf *.o *.gch core
	@ \rm -rf $(TESTFILES)/*.o $(TESTFILES)/*.gch $(TESTFILES)/core

.PHONY : zap
zap: clean
	@ \rm -rf player-test *~
	@ \rm -rf $(TESTFILES)/*~
