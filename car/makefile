CC=g++
CFLAGS=-c -stdlib=libc++ -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:			car

car:				RaspberryPi.o I2cBus.o PCA9685.o PwmEsc.o PwmServo.o Car.o app.o
	$(CC) $(LDFLAGS) RaspberryPi.o I2cBus.o PCA9685.o PwmEsc.o PwmServo.o Car.o app.o -o car $(LDTRAIL)

app.o: 				app.cpp
	$(CC) $(CFLAGS) app.cpp $(CTRAIL)

Car.o:				Car.cpp
	$(CC) $(CFLAGS) Car.cpp $(CTRAIL)

PwmServo.o:			PwmServo.cpp
	$(CC) $(CFLAGS) PwmServo.cpp $(CTRAIL)

PwmEsc.o:			PwmEsc.cpp
	$(CC) $(CFLAGS) PwmEsc.cpp $(CTRAIL)

PCA9685.o:	PCA9685.cpp
	$(CC) $(CFLAGS) PCA9685.cpp $(CTRAIL)

I2cBus.o:	I2cBus.cpp
	$(CC) $(CFLAGS) I2cBus.cpp $(CTRAIL)

RaspberryPi.o:	RaspberryPi.cpp
	$(CC) $(CFLAGS) RaspberryPi.cpp $(CTRAIL)
	
