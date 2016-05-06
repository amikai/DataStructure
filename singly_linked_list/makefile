
OBJECTS = main.o LinkedList.o
CC = gcc

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: LinkedList.h
LinkedList.o: LinkedList.h

clean:
	rm main $(OBJECTS)

run: main
	./main
