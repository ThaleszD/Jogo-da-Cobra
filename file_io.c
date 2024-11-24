#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>

void saveStatistics(int score) {
    FILE *file = fopen("stats.bin", "ab");
    if (file) {
        fwrite(&score, sizeof(int), 1, file);
        fclose(file);
    }
}

void displayStatistics() {
    FILE *file = fopen("stats.bin", "rb");
    if (!file) {
        printf("Sem estatísticas salvas.\n");
        return;
    }

    int score;
    printf("=== Estatísticas ===\n");
    while (fread(&score, sizeof(int), 1, file)) {
        printf("Pontuação: %d\n", score);
    }
    fclose(file);
}
