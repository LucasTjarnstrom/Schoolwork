# Makefile

# Filkataloger
SOURCE = source
TESTFILES = test-files

# Kompilator
CCC = g++

# Kompilatorflaggor
CCFLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Werror -Weffc++

# Huvudmål
character-test: $(TESTFILES)/test_main.o $(TESTFILES)/Character.o $(TESTFILES)/character-test.cc
	$(CCC) $(CCFLAGS) $(TESTFILES)/test_main.o $(TESTFILES)/Character.o $(TESTFILES)/character-test.cc -o character-test

# Delmål
test_main.o: $(TESTFILES)/test_main.cc
	$(CCC) $(CCFLAGS) -c $(TESTFILES)/test_main.cc -o $(TESTFILES)/test_main.o

$(TESTFILES)/Character.o : Character.h Character.cc
	$(CCC) $(CCFLAGS) -c Character.cc -o $(TESTFILES)/Character.o

.PHONY : clean
clean:
	@ \rm -rf *.o *.gch core
	@ \rm -rf $(TESTFILES)/*.o $(TESTFILES)/*.gch $(TESTFILES)/core

.PHONY : zap
zap: clean
	@ \rm -rf character-test *~
	@ \rm -rf $(TESTFILES)/*~
