IDIR =../include
CC=g++ -std=c++11
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm -lSDL2 -lSDL2_image -lSDL2_ttf

_DEPS = gui.h gui_manager.h texture_manager.h game_objects.h screens.h map.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = gui.o gui_manager.o game_objects.o texture_manager.o screens.o main.o map.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

cpplin: cpplint tropas.cpp testes.cpp unidades.cpp utils.cpp tabuleiro.cpp engine.cpp

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(ODIR)/*.gcno *~ $(ODIR)/*.gcda *~ testes *~
