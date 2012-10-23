CC = g++
CFLAGS = -g
OBJS = main.o board.o

all: $(OBJS)
	$(CC) $(OBJS) 

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

board.o: board.cpp board.h
	$(CC) -c board.cpp $(CFLAGS)

clean:
	rm -f $(OBJS)	
