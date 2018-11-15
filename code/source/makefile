IDIR =../include
CC=g++
CFLAGS=-ftest-coverage -fprofile-arcs -I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = personagens.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = personagens.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

personagens: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 