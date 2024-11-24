#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 20

typedef struct {
    char grid[BOARD_SIZE][BOARD_SIZE];
} Board;

int loadBoard(Board *board, int level);
void displayBoard(Board *board);

#endif
