CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:			car

car:			PwmServo.o Car.o app.o
	$(CC) $(LDFLAGS) PwmServo.o Car.o app.o -o car $(LDTRAIL)

app.o: 		app.cpp
	$(CC) $(CFLAGS) app.cpp $(CTRAIL)

Car.o:		Car.cpp
	$(CC) $(CFLAGS) Car.cpp $(CTRAIL)

PwmServo.o:	PwmServo.cpp
	$(CC) $(CFLAGS) PwmServo.cpp $(CTRAIL)

