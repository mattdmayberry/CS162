PROGS = marsOne
HEADERS = Room.h Item.h Biodome.h Module.h Biodome_1.h Biodome_2.h Biodome_3.h Control_Room.h Duct_tape.h Hammer.h Helmet.h Ipod.h Key.h Module_1.h Module_2.h Module_3.h Module_4.h Module_5.h Module_6.h Outside_south.h Outside.h Pack.h Player.h Rover.h Screw_driver.h Suit.h Tank.h Timer.h
SRC = Room.cpp Item.cpp Module.cpp Biodome.cpp Biodome_1.cpp Biodome_2.cpp Biodome_3.cpp Control_Room.cpp Duct_tape.cpp Hammer.cpp Helmet.cpp Ipod.cpp Key.cpp Module_1.cpp Module_2.cpp Module_3.cpp Module_4.cpp Module_5.cpp Module_6.cpp Outside_south.cpp Outside.cpp Pack.cpp Player.cpp Rover.cpp Screw_driver.cpp Suit.cpp Tank.cpp Timer.cpp main.cpp

all: $(PROGS)

marsOne: $(HEADERS) $(SRC)

	g++ -g $(HEADERS) $(SRC) -o marsOne


clean:
	rm -f $(PROGS) *.o *~