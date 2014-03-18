CC=g++
CFLAGS=-c -Wall
CTRAIL=-lwiringPi
LDFLAGS=
LDTRAIL=-lwiringPi

all:	pca9685

pca9685:	Pca9685.o test.o ../gpio/gpio.o
	$(CC) $(LDFLAGS) ../gpio/gpio.o Pca9685.o test.o -o test $(LDTRAIL)

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp $(CTRAIL)

Pca9685.o:	Pca9685.cpp
	$(CC) $(CFLAGS) Pca9685.cpp $(CTRAIL)

../gpio/gpio.o:	../gpio/gpio.cpp
	make -C ../gpio/ gpio.o
	
clean_objects:
	rm -rf *.o

