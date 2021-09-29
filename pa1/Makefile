#------100dd------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 1
#
# make                   makes Lex
# make ListClient        makes ListClient
# make clean             removes all binaries
# make checkClient       checks ListClient for memory errors
# make checkLex          checks Lex for memory errors
#------------------------------------------------------------------------------

CC = clang
CFLAGS = -std=c11 -Wall  -Wpedantic -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=*.o)
EXECBIN = Lex ListClient

.PHONY = all clean

all: $(EXECBIN)

Lex: Lex.o List.o
	$(CC) -o Lex Lex.o List.o

ListClient: ListClient.o List.o
	$(CC) -o ListClient ListClient.o List.o

clean:
	rm -f $(EXECBIN) *.o


%.o: %.c
	$(CC) $(CFLAGS) -c $<

gitUpdate: 
	git add *.[ch] Makefile README.md
	git commit -m "update"
	git push

valgrind: all
	valgrind --leak-check=full ./Lex ./test_files/infiles/in2.txt outfile
