OBJECTS = main.o DoublyLinkedList.o
CC = gcc

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

%.o: %.c
	$(CC) -c $<

.PHONY: clean
clean:
	@rm main $(OBJECTS)

.PHONY: run
run: #atom run
	make && ./main && make clean
