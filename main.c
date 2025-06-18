#include <stdio.h>

void mostrarTabuleiro(char tabuleiro[8][8]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[8][8];

    // Preencher o tabuleiro com espaços vazios
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Colocar peões brancos na linha 6
    for (int j = 0; j < 8; j++) {
        tabuleiro[6][j] = 'P';
    }

    // Mostrar tabuleiro inicial
    printf("Tabuleiro inicial:\n");
    mostrarTabuleiro(tabuleiro);

    int origem_col, destino_linha;
    char origem_letra;

    printf("Digite a coluna do peao que quer mover (a-h): ");
    scanf(" %c", &origem_letra);
    printf("Digite o numero da linha de destino (1-8): ");
    scanf("%d", &destino_linha);

    origem_col = origem_letra - 'a';
    int origem_linha = 6;
    int dest_linha = 8 - destino_linha;

    // Movimento simples de peão
    if (tabuleiro[origem_linha][origem_col] == 'P' && dest_linha == origem_linha - 1) {
        tabuleiro[origem_linha][origem_col] = '.';
        tabuleiro[dest_linha][origem_col] = 'P';
        printf("Movimento realizado!\n");
    } else {
        printf("Movimento invalido.\n");
    }

    mostrarTabuleiro(tabuleiro);

    return 0;
}
