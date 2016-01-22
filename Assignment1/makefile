PROGS := conways

all: ${PROGS}

conways: main.cpp Grid.h Grid.cpp 
	g++ -g main.cpp Grid.h Grid.cpp -o conways

clean:
	rm -f ${PROGS} *.o *~