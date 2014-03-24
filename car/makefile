CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:			car

car:				PwmController.o PwmServo.o Car.o app.o
	$(CC) $(LDFLAGS) PwmController.o PwmServo.o Car.o app.o -o car $(LDTRAIL)

app.o: 				app.cpp
	$(CC) $(CFLAGS) app.cpp $(CTRAIL)

Car.o:				Car.cpp
	$(CC) $(CFLAGS) Car.cpp $(CTRAIL)

PwmServo.o:			PwmServo.cpp
	$(CC) $(CFLAGS) PwmServo.cpp $(CTRAIL)

PwmController.o:	PwmController.cpp
	$(CC) $(CFLAGS) PwmController.cpp $(CTRAIL)
