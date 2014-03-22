CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:			test

test:			I2cSlave.o I2cMaster.o RaspberryPi.o test.o
	$(CC) $(LDFLAGS) I2cSlave.o I2cMaster.o RaspberryPi.o test.o -o test $(LDTRAIL)

test.o: 		test.cpp
	$(CC) $(CFLAGS) test.cpp $(CTRAIL)

RaspberryPi.o:	RaspberryPi.cpp
	$(CC) $(CFLAGS) RaspberryPi.cpp $(CTRAIL)

I2cMaster.o:	I2cMaster.cpp
	$(CC) $(CFLAGS) I2cMaster.cpp $(CTRAIL)

I2cSlave.o:		I2cSlave.cpp
	$(CC) $(CFLAGS) I2cSlave.cpp $(CTRAIL)


clean_objects:
	rm -rf *.o
