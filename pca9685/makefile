CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:	pca9685

pca9685:	pca9685.o test.o gpio.o
	$(CC) $(LDFLAGS) ../gpio/gpio.o pca9685.o test.o -o test $(LDTRAIL)

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp $(CTRAIL)

pca9685.o: pca9685.cpp
	$(CC) $(CFLAGS) pca9685.cpp $(CTRAIL)

gpio.o:	../gpio/gpio.cpp
	make -C ../gpio/ all
	
clean_objects:
	rm -rf *.o

