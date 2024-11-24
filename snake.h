#ifndef SNAKE_H
#define SNAKE_H

typedef struct SnakePart {
    int x, y;
    struct SnakePart *next;
} SnakePart;

typedef struct Snake {
    SnakePart *head;
    SnakePart *tail;
    int length;
} Snake;

Snake* createSnake(int startX, int startY);
void freeSnake(Snake *snake);
void moveSnake(Snake *snake, int dx, int dy);

#endif
