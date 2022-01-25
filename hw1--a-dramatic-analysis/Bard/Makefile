CC = g++
CFLAGS = -std=c++17 -O2 -Wall -g
SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC: .cpp = *.o)
EXECBIN = bard

.PHONY = all clean debug

all: $(EXECBIN)

clean:
	rm -f $(EXECBIN) *.o
	
$(EXECBIN): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(EXECBIN)

%.o: %.c
	$(CC) $(CFLAGS)-c $<
	
valgrind: clean all
	valgrind --leak-check=full ./bard simple-input.txt myOutput.txt 