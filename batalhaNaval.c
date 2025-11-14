#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro 10x10
#define NAVIO 3      // Valor que representa o navio no tabuleiro
#define TAM_NAVIO 3  // Tamanho dos navios (3 posições cada)


int main() {
    // -------------------------------
    // 1. CRIAÇÃO DO TABULEIRO 10x10
    // -------------------------------
    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -----------------------------------------
    // 2. DEFINIÇÃO DOS NAVIOS (vetores)
    // -----------------------------------------

    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais escolhidas no código
    // Você pode alterar para testar diferentes posições

    int linhaH = 2;   // Linha inicial do navio horizontal
    int colunaH = 4;  // Coluna inicial do navio horizontal

    int linhaV = 5;   // Linha inicial do navio vertical
    int colunaV = 1;  // Coluna inicial do navio vertical

    // -----------------------------------------------------
    // 3. VALIDAÇÃO DA POSIÇÃO DOS NAVIOS
    // -----------------------------------------------------

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }

    // Verifica sobreposição dos navios de forma simples
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linhaH == linhaV + i && colunaH <= colunaV && colunaH + 2 >= colunaV) {
            printf("Erro: navios se sobrepoem!\n");
            return 1;
        }
    }

    // ----------------------------------------------
    // 4. POSICIONAMENTO DO NAVIO HORIZONTAL no tabuleiro
    // ----------------------------------------------

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // ----------------------------------------------
    // 5. POSICIONAMENTO DO NAVIO VERTICAL no tabuleiro
    // ----------------------------------------------

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // -------------------------------
    // 6. EXIBIÇÃO DO TABULEIRO
    // -------------------------------

    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);  // Espaço para melhor visualização
        }
        printf("\n");
    }

    return 0;
}
