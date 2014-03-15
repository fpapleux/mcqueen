CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:	gpio

gpio:	gpio.o test.o
	$(CC) $(LDFLAGS) test.o gpio.o -o testgpio $(LDTRAIL)

test.o:	test.cpp
	$(CC) $(CFLAGS) test.cpp $(CTRAIL)

gpio.o:	gpio.cpp
	$(CC) $(CFLAGS) gpio.cpp $(CTRAIL)

clean:
	rm -rf *.o testgpio

