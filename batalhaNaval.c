#include <stdio.h>

#define TAM 10           // Tamanho do tabuleiro
#define NAVIO 3          // Marca navio no tabuleiro
#define HABILIDADE 5     // Marca área de habilidade
#define HAB 5            // Tamanho das matrizes de habilidade (5x5)

// Função para imprimir matrizes (para debug opcional)
void imprimirMatriz(int mat[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Sobrepõe uma matriz de habilidade ao tabuleiro centralizada no ponto origem
void aplicarHabilidade(int tab[TAM][TAM], int hab[HAB][HAB], int linha, int coluna) {

    int offset = HAB / 2; // centro da matriz de habilidade

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            // Só marca habilidade se mat[i][j] == 1
            if (hab[i][j] == 1) {

                int linhaTab = linha + (i - offset);
                int colunaTab = coluna + (j - offset);

                // Garantir que não ultrapassa o tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM &&
                    colunaTab >= 0 && colunaTab < TAM) {

                    // NÃO sobrescreve navios
                    if (tab[linhaTab][colunaTab] != NAVIO) {
                        tab[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {

   int tabuleiro[TAM][TAM];

    // ---------------------------------------------------------
    // 1. Inicializa o tabuleiro com água (0)
    // ---------------------------------------------------------
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // ---------------------------------------------------------
    // 2. Posiciona alguns navios para visualização
    // ---------------------------------------------------------

    // Navio horizontal no topo
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[2][6] = NAVIO;

    // Navio vertical à esquerda
    tabuleiro[5][2] = NAVIO;
    tabuleiro[6][2] = NAVIO;
    tabuleiro[7][2] = NAVIO;

    // ---------------------------------------------------------
    // 3. Matrizes das habilidades (preenchidas dinamicamente)
    // ---------------------------------------------------------

    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // -------------------------------
    // HABILIDADE 1 — CONE (↧)
    // -------------------------------
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            // topo é 1
            if (i == 0 && j == HAB / 2) {
                cone[i][j] = 1;
            }
            // segunda linha: 1 no meio +-1
            else if (i == 1 && j >= (HAB/2)-1 && j <= (HAB/2)+1) {
                cone[i][j] = 1;
            }
            // terceira linha: cone se abre ainda mais
            else if (i == 2 && j >= (HAB/2)-2 && j <= (HAB/2)+2) {
                cone[i][j] = 1;
            }
            else {
                cone[i][j] = 0;
            }
        }
    }

    // -------------------------------
    // HABILIDADE 2 — CRUZ (+)
    // -------------------------------
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == HAB/2 || j == HAB/2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // -------------------------------
    // HABILIDADE 3 — OCTAEDRO (♦)
    // -------------------------------
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int dist = abs(centro - i) + abs(centro - j);

            // forma do losango
            if (dist <= 2) {  
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ---------------------------------------------------------
    // 4. Aplicar habilidades no tabuleiro (posições fixas)
    // ---------------------------------------------------------

    aplicarHabilidade(tabuleiro, cone, 1, 1);      // Cone perto do topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro na direita inferior

    // ---------------------------------------------------------
    // 5. Exibir tabuleiro final
    // ---------------------------------------------------------

    printf("\n===== TABULEIRO COM HABILIDADES =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0) {
                printf("0 ");
            }
            else if (tabuleiro[i][j] == NAVIO) {
                printf("3 ");
            }
            else if (tabuleiro[i][j] == HABILIDADE) {
                printf("5 ");
            }
        }
        printf("\n");
    }
    return 0;
}
