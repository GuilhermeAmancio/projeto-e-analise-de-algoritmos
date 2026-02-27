#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o mínimo entre dois valores
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;

    printf("Digite o numero de chaves: ");
    scanf("%d", &n);

    int keys[n];
    float freq[n]; // probabilidades de cada chave

    printf("Digite as chaves em ordem crescente:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    printf("Digite a frequencia/probabilidade de cada chave:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &freq[i]);

    // dp[i][j] = custo mínimo para chaves i..j
    float dp[n][n];
    int root[n][n]; // raiz da subárvore i..j

    // Inicialização: custo de uma chave individual é sua própria frequência
    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
        root[i][i] = i;
    }

    // Preenche dp para subárvores de tamanho 2 a n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e9; // infinito grande
            float sum = 0;
            for (int k = i; k <= j; k++)
                sum += freq[k];

            // Tenta cada chave como raiz e escolhe a de menor custo
            for (int r = i; r <= j; r++) {
                float left = (r > i) ? dp[i][r - 1] : 0;
                float right = (r < j) ? dp[r + 1][j] : 0;
                float cost = left + right + sum;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Custo minimo da arvore binaria de busca otima: %.2f\n", dp[0][n - 1]);

    // Opcional: imprimir a raiz de cada subárvore
    printf("Raizes de cada subarvore:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            printf("%d ", root[i][j]);
        printf("\n");
    }

    return 0;
}