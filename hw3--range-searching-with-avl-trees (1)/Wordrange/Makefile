CC = g++
CFLAGS = -std=c++17 -O2 -Wall -g
SRC = $(wildcard *.cpp)
OBJ = $(SRC: .cpp = *.o)
EXECBIN = wordrange

.PHONY = all clean debug

all: $(EXECBIN)

clean:
	rm -f $(EXECBIN) *.o
	
$(EXECBIN): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(EXECBIN)

%.o: %.c
	$(CC) $(CFLAGS)-c $<
	
