#include <stdio.h>

void mover_torre(int x, int y, int casas) {
    // Movimento para cima
    if (casas > 0 && x > 0) {
        printf("Cima\n");
        mover_torre(x-1, y, casas-1);
    }
    // Movimento para baixo
    if (casas > 0 && x < 7) {
        printf("Baixo\n");
        mover_torre(x+1, y, casas-1);
    }
    // Movimento para a esquerda
    if (casas > 0 && y > 0) {
        printf("Esquerda\n");
        mover_torre(x, y-1, casas-1);
    }
    // Movimento para a direita
    if (casas > 0 && y < 7) {
        printf("Direita\n");
        mover_torre(x, y+1, casas-1);
    }
}

void mover_bispo(int x, int y, int casas, int direcao_x, int direcao_y) {
    // Movimento diagonal superior-esquerda
    if (casas > 0 && x > 0 && y > 0) {
        printf("Cima\n");
        printf("Esquerda\n");
        mover_bispo(x-1, y-1, casas-1, direcao_x, direcao_y);
    }
    // Movimento diagonal superior-direita
    if (casas > 0 && x > 0 && y < 7) {
        printf("Cima\n");
        printf("Direita\n");
        mover_bispo(x-1, y+1, casas-1, direcao_x, direcao_y);
    }
    // Movimento diagonal inferior-esquerda
    if (casas > 0 && x < 7 && y > 0) {
        printf("Baixo\n");
        printf("Esquerda\n");
        mover_bispo(x+1, y-1, casas-1, direcao_x, direcao_y);
    }
    // Movimento diagonal inferior-direita
    if (casas > 0 && x < 7 && y < 7) {
        printf("Baixo\n");
        printf("Direita\n");
        mover_bispo(x+1, y+1, casas-1, direcao_x, direcao_y);
    }
}

void mover_rainha(int x, int y, int casas) {
    // Movimento vertical (como a Torre)
    mover_torre(x, y, casas);
    // Movimento diagonal (como o Bispo)
    mover_bispo(x, y, casas, 0, 0);
}

void mover_cavalo(int x, int y) {
    // Loop aninhado para todas as possíveis posições do Cavalo
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            // Verificar se o movimento é um "L" válido (2 casas para cima/baixo e 1 para direita/esquerda)
            if (abs(i) + abs(j) == 3) {
                int novo_x = x + i;
                int novo_y = y + j;
                if (novo_x >= 0 && novo_x < 8 && novo_y >= 0 && novo_y < 8) {
                    printf("Cavalo: (%d, %d)\n", novo_x, novo_y);
                }
            }
        }
    }
}

int main() {
    int x = 4, y = 4; // Posição inicial

    printf("Movimentos da Torre:\n");
    mover_torre(x, y, 3); // A Torre se move 3 casas para cada direção
    printf("\n");

    printf("Movimentos do Bispo:\n");
    mover_bispo(x, y, 3, 0, 0); // O Bispo se move 3 casas em diagonal
    printf("\n");

    printf("Movimentos da Rainha:\n");
    mover_rainha(x, y, 3); // A Rainha se move 3 casas em todas as direções
    printf("\n");

    printf("Movimentos do Cavalo:\n");
    mover_cavalo(x, y); // O Cavalo faz os movimentos "L"
    printf("\n");

    return 0;
}
