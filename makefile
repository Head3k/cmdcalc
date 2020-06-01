CC = gcc
CFLAGS = -Wall -Werror
CFLAGS_TEST = -I thirdparty -Wall -Werror
EXECUTABLE = ./cmdcalc
OBJECTS = ./build/main.o ./build/analysis.o ./build/interface.o ./build/rework.o ./build/calculation.o

all: cmdcalc 
.PHONY: clean

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

./build/main.o: ./src/main.c
		$(CC) $(CFLAGS) -o $@ -c $^

./build/analysis.o: ./src/analysis.c
		$(CC) $(CFLAGS) -o $@ -c $^

./build/interface.o: ./src/interface.c
		$(CC) $(CFLAGS) -o $@ -c $^

./build/rework.o: ./src/rework.c
		$(CC) $(CFLAGS) -o $@ -c $^

./build/calculation.o: ./src/calculation.c
		$(CC) $(CFLAGS) -o $@ -c $^

clean: 
		rm ./build/*.o
		rm ./bin/*
