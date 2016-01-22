PROGS = battle
HEADERS = Stack.h Queue.h Character.h List.h Goblin.h Shadow.h Reptile.h BlueMen.h Barbarian.h Combat.h Creature.h
SRC = Creature.cpp Stack.cpp Queue.cpp Character.cpp List.cpp  Combat.cpp main.cpp
CREATURES = Goblin.cpp Shadow.cpp Reptile.cpp BlueMen.cpp Barbarian.cpp

all: $(PROGS)

battle: $(HEADERS) $(SRC) $(CREATURES)

	g++ -g $(SRC) $(CREATURES) -o battle


clean:
	rm -f $(PROGS) *.o *~