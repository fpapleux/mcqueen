CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:			test

test:			test.o I2cMaster.o RaspberryPi.o
	$(CC) $(LDFLAGS) RaspberryPi.o test.o -o test $(LDTRAIL)

test.o: 		test.cpp
	$(CC) $(CFLAGS) test.cpp $(CTRAIL)

RaspberryPi.o:	RaspberryPi.cpp
	$(CC) $(CFLAGS) RaspberryPi.cpp $(CTRAIL)

I2cMaster.o:	I2cMaster.cpp
	$(CC) $(CFLAGS) I2cMaster.cpp $(CTRAIL)

clean_objects:
	rm -rf *.o
