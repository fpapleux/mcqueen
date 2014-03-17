CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:	app

app:	gpio/gpio.o pca9685/pca9685.o app.o
	$(CC) $(LDFLAGS) gpio/gpio.o pca9685/pca9685.o app.o -o mcqueen $(LDTRAIL)

app.o: app.cpp
	$(CC) $(CFLAGS) app.cpp $(CTRAIL)

pca9685/pca9685.o:	pca9685/pca9685.cpp
	make -C pca9685/ pca9685.o

gpio/gpio.o:	gpio/gpio.cpp
	make -C gpio/ gpio.o
	
clean_objects:
	rm -rf *.o

