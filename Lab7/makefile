PROGS := battle

all: ${PROGS}

battle: Stack.h Queue.h Character.h List.h Goblin.h Shadow.h Reptile.h BlueMen.h Barbarian.h Combat.h Stack.cpp Queue.cpp Character.cpp List.cpp Goblin.cpp Shadow.cpp Reptile.cpp BlueMen.cpp Barbarian.cpp Combat.cpp main.cpp

g++ -g Stack.h Queue.h Character.h List.h Goblin.h Shadow.h Reptile.h BlueMen.h Barbarian.h Combat.h Stack.cpp Queue.cpp Character.cpp List.cpp Goblin.cpp Shadow.cpp Reptile.cpp BlueMen.cpp Barbarian.cpp Combat.cpp main.cpp -o battle


clean:
	rm -f ${PROGS} *.o *~