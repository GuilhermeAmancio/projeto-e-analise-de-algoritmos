/**
 * ALGORITMO DE ELIMINAÇÃO GAUSSIANA (SEM PIVOTAMENTO)
 * * Este programa resolve sistemas lineares do tipo Ax = b.
 * O processo é dividido em duas etapas principais:
 * * 1. FASE DE ELIMINAÇÃO: Transforma a matriz original em uma matriz 
 * triangular superior. Para cada coluna (k), o algoritmo calcula um 
 * 'multiplicador' para cada linha abaixo dela (i), subtraindo a linha 
 * do pivô escalonada para zerar os elementos abaixo da diagonal principal.
 * * 2. SUBSTITUIÇÃO RETROSPECTIVA: Uma vez que a matriz é triangular, a 
 * última variável (x[n-1]) pode ser resolvida diretamente. O algoritmo 
 * então "sobe" resolvendo as variáveis anteriores, substituindo os 
 * valores já conhecidos nas equações de cima.
 */


#include <stdio.h>

int main() {
    int n;

    printf("Digite a ordem do sistema (n): ");
    if (scanf("%d", &n) != 1) return 1;

    double matriz[n][n + 1];
    double x[n];

    printf("Digite todos os %d elementos da matriz aumentada em sequencia:\n", n * (n + 1));
    printf("Exemplo: a11 a12... a1n b1 a21...\n");

    // Lendo tudo no formato sequencial
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (scanf("%lf", &matriz[i][j]) != 1) {
                printf("Erro na leitura dos dados.\n");
                return 1;
            }
        }
    }

    // --- FASE 1: ELIMINAÇÃO (Conforme a imagem) ---
    for (int k = 0; k < n - 1; k++) {
        if (matriz[k][k] == 0) {
            printf("Pivo nulo. Sistema pode ser singular.\n");
            return 1;
        }

        for (int i = k + 1; i < n; i++) {
            double multiplicador = matriz[i][k] / matriz[k][k];
            for (int j = k; j <= n; j++) {
                matriz[i][j] -= multiplicador * matriz[k][j];
            }
        }
    }

    // --- FASE 2: SUBSTITUIÇÃO RETROSPECTIVA ---
    for (int i = n - 1; i >= 0; i--) {
        double soma = 0;
        for (int j = i + 1; j < n; j++) {
            soma += matriz[i][j] * x[j];
        }
        x[i] = (matriz[i][n] - soma) / matriz[i][i];
    }

    // Resultado
    printf("\nSolucoes encontradas:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}