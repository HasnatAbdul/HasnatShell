# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= functions.c main.c

# generic build details

CC=      cc
COPT=    -O
CFLAGS=  -lm -g

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ)

# dependencies
main.o:  main.c  functions.h
functions.o:  functions.c functions.h

