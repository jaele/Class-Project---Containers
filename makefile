CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = test
MAKEFLAGS = -k

all: $(PROGS)

test:
	$(CC) $(CFLAGS) testDriver.cpp Creature.cpp Barbarian.cpp Goblin.cpp ReptilePeople.cpp BlueMen.cpp Shadow.cpp Queue.cpp Stack.cpp -o test
clean:
	rm -f *.o test
