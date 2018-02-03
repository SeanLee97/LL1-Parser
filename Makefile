CC = g++
OBJECTS = driver.o scan.o grammar.o
INCLUDES = scan.h grammar.h

all : driver

driver : $(OBJECTS)
	$(CC) -g -o driver $(OBJECTS)

driver.o : driver.cpp scan.h
	$(CC) -c -g driver.cpp

scan.o : scan.cpp scan.h
	$(CC) -c -g scan.cpp

grammar.o : grammar.cpp grammar.h
	$(CC) -c -g grammar.cpp

clean :
	rm -f driver $(OBJECTS)
