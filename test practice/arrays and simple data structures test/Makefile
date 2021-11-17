CC = g++
CFLAGS = -std=c++17 -O2 -Wall -g
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=*.o)
EXECBIN = foo

.PHONY = all clean debug

all: $(EXECBIN)

clean:
	rm -f $(OBJ) $(EXECBIN)

debug: CFLAGS += -g
debug: clean all

$(EXECBIN): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(EXECBIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
