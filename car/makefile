CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:			car

car:			Car.o app.o
	$(CC) $(LDFLAGS) car.o app.o -o car $(LDTRAIL)

app.o: 		app.cpp
	$(CC) $(CFLAGS) app.cpp $(CTRAIL)

Car.o:		Car.cpp
	$(CC) $(CFLAGS) Car.cpp $(CTRAIL)

