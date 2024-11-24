#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "board.h"
#include "file_io.h"


void showMenu() {
    printf("=== Jogo Snake ===\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Estatísticas\n");
    printf("3. Sair\n");
}

int main() {
    int option;
    Board board;
    Snake *snake = NULL;

    while (1) {
        showMenu();

        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                snake = createSnake(5, 5);

                for (int level = 1; level <= 5; level++) {
                    if (!loadBoard(&board, level)) {
                        printf("Erro ao carregar a fase %d\n", level);
                        break;
                    }

                    playGame(&board, snake);
                }

                freeSnake(snake);
                break;

            case 2:
                displayStatistics();
                break;

            case 3:
                printf("Saindo do jogo. Até mais!\n");
                return 0;

            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
