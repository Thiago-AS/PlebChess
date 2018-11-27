IDIR =../include
CC=g++ -std=c++11
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm -lSDL2 -lSDL2_image

_DEPS = gui.h gui_manager.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = gui.o gui_manager.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

cpplin: cpplint tropas.cpp testes.cpp unidades.cpp utils.cpp tabuleiro.cpp engine.cpp

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(ODIR)/*.gcno *~ $(ODIR)/*.gcda *~ testes *~
