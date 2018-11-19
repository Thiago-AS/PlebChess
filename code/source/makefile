IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = cavaleiro.hpp arqueiro.hpp guerreiro.hpp catch.hpp mina.hpp lenhadora.hpp fortaleza.hpp utils.hpp quadrado.hpp tabuleiro.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
	
_OBJ = testes.o cavaleiro.o arqueiro.o guerreiro.o mina.o lenhadora.o fortaleza.o utils.o quadrado.o tabuleiro.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(ODIR)/*.gcno *~ $(ODIR)/*.gcda *~ testes *~
