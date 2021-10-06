CC = g++
CFLAGS = -std=c++11 -O2 -Wall -g
SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC: .cpp = *.o)
EXECBIN = bard

.PHONY = all clean debug

all: $(EXECBIN)

clean:
	rm -f $(OBJ) $(EXECBIN)
	
$(EXECBIN): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(EXECBIN)

%.o: %.c
	$(CC) $(CFLAGS)-c $<