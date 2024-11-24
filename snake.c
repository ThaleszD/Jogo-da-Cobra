#include "snake.h"
#include <stdlib.h>
#include <stdio.h>

Snake* createSnake(int startX, int startY) {
    Snake *snake = (Snake *)malloc(sizeof(Snake));
    SnakePart *head = (SnakePart *)malloc(sizeof(SnakePart));
    head->x = startX;
    head->y = startY;
    head->next = NULL;
    snake->head = head;
    snake->tail = head;
    snake->length = 1;
    return snake;
}

void freeSnake(Snake *snake) {
    SnakePart *current = snake->head;
    while (current != NULL) {
        SnakePart *next = current->next;
        free(current);
        current = next;
    }
    free(snake);
}

void moveSnake(Snake *snake, int dx, int dy) {
    SnakePart *newHead = (SnakePart *)malloc(sizeof(SnakePart));
    newHead->x = snake->head->x + dx;
    newHead->y = snake->head->y + dy;
    newHead->next = snake->head;
    snake->head = newHead;

    if (snake->length > 1) {
        SnakePart *prev = NULL;
        SnakePart *current = snake->tail;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        free(current);
        prev->next = NULL;
        snake->tail = prev;
    }
}
