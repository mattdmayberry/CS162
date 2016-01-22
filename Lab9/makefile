PROGS := lab9

all: ${PROGS}

lab9: Stack.h Queue.h Stack.cpp Queue.cpp main.cpp
	g++ -g Stack.h Queue.h Stack.cpp Queue.cpp main.cpp -o lab9


clean:
	rm -f ${PROGS} *.o *~