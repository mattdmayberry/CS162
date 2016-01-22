PROGS := linkedList2

all: ${PROGS}

linkedList2: Stack.h Queue.h Stack.cpp Queue.cpp main.cpp
	g++ -g Stack.h Queue.h Stack.cpp Queue.cpp main.cpp -o linkedList2


clean:
	rm -f ${PROGS} *.o *~