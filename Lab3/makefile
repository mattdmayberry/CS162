PROGS := dice

all: ${PROGS}

dice: main.cpp Dice.h Dice.cpp LoadedDice.h LoadedDice.cpp 
	g++ -g main.cpp Dice.h Dice.cpp LoadedDice.h LoadedDice.cpp -o dice

clean:
	rm -f ${PROGS} *.o *~