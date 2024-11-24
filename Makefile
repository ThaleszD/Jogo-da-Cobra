CC = gcc
CFLAGS = -Wall -Wextra
OBJ = main.o snake.o board.o file_io.o

all: snake_game

snake_game: $(OBJ)
	$(CC) $(CFLAGS) -o snake_game $(OBJ)

main.o: main.c snake.h board.h file_io.h
	$(CC) $(CFLAGS) -c main.c

snake.o: snake.c snake.h
	$(CC) $(CFLAGS) -c snake.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

file_io.o: file_io.c file_io.h
	$(CC) $(CFLAGS) -c file_io.c

clean:
	rm -f *.o snake_game
