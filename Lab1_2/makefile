
PROGS := lab11 lab12

all: ${PROGS}

lab11: lab1-1.cpp
	g++ -g lab1-1.cpp -o lab11


lab12: f.h f.cpp g.h g.cpp lab1-2.cpp
	g++ -g f.h f.cpp g.h g.cpp lab1-2.cpp -o lab12

clean:
	rm -f ${PROGS} *.o *~
