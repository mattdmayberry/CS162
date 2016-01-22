PROGS := shop

all: ${PROGS}

shop: main.cpp List.h List.cpp Item.h Item.cpp ClubItem.h ClubItem.cpp
	g++ -g main.cpp List.h List.cpp Item.h Item.cpp ClubItem.h ClubItem.cpp -o shop

clean:
	rm -f ${PROGS} *.o *~