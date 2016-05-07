
OBJECTS = main.o LinkedList.o
CC = gcc

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

%.o: %.c %.h
	$(CC) -c $<

.PHONY: clean
clean:
	@rm main *.o

.PHONY: run
run: #atom run
	./main && make clean
