IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = tropas.hpp catch.hpp unidades.hpp utils.hpp quadrado.hpp tabuleiro.hpp engine.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
	
_OBJ = testes.o tropas.o unidades.o utils.o quadrado.o tabuleiro.o engine.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(ODIR)/*.gcno *~ $(ODIR)/*.gcda *~ testes *~
