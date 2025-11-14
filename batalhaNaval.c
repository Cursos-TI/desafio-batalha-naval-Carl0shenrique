#include <stdio.h>

#define TAM 10         // Tamanho do tabuleiro 10x10
#define NAVIO 3        // Valor que representa uma parte de navio
#define TAM_NAVIO 3    // Cada navio tem tamanho 3

// Função para verificar se uma posição já está ocupada
int ocupado(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] != 0;
}
int main() {

      // -----------------------------
    // 1. CRIAÇÃO DO TABULEIRO 10x10
    // -----------------------------
    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---------------------------------------
    // 2. DEFINIÇÃO DAS COORDENADAS DOS 4 NAVIOS
    // ---------------------------------------

    // Navio horizontal
    int linhaH = 2, colunaH = 3;

    // Navio vertical
    int linhaV = 5, colunaV = 7;

    // Navio diagonal crescente (↘)
    int linhaD1 = 1, colunaD1 = 1;

    // Navio diagonal decrescente (↙)
    int linhaD2 = 6, colunaD2 = 8;

    // ---------------------------------------
    // 3. VALIDAÇÃO E POSICIONAMENTO DOS NAVIOS
    // ---------------------------------------

    // NAVIO HORIZONTAL (↦)
    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (ocupado(tabuleiro, linhaH, colunaH + i)) {
            printf("Erro: navio horizontal sobreposto!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // NAVIO VERTICAL (↧)
    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (ocupado(tabuleiro, linhaV + i, colunaV)) {
            printf("Erro: navio vertical sobreposto!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // NAVIO DIAGONAL CRESCENTE (↘): linha++, coluna++
    if (linhaD1 + TAM_NAVIO > TAM || colunaD1 + TAM_NAVIO > TAM) {
        printf("Erro: navio diagonal ↘ nao cabe no tabuleiro!\n");
        return 1;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (ocupado(tabuleiro, linhaD1 + i, colunaD1 + i)) {
            printf("Erro: navio diagonal ↘ sobreposto!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
    }

    // NAVIO DIAGONAL DECRESCENTE (↙): linha++, coluna--
    if (linhaD2 + TAM_NAVIO > TAM || colunaD2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: navio diagonal ↙ nao cabe no tabuleiro!\n");
        return 1;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (ocupado(tabuleiro, linhaD2 + i, colunaD2 - i)) {
            printf("Erro: navio diagonal ↙ sobreposto!\n");
            return 1;
        }
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
    }

    // -----------------------------
    // 4. IMPRESSÃO DO TABULEIRO
    // -----------------------------
    printf("\n===== TABULEIRO COMPLETO =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
