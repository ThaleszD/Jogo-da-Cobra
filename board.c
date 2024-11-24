#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int loadBoard(Board *board, int level) {
    char filename[20];
    sprintf(filename, "fase%d.txt", level);

    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            fscanf(file, " %c", &board->grid[i][j]);
        }
    }
    fclose(file);
    return 1;
}

void displayBoard(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}
