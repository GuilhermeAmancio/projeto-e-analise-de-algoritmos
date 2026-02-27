#include <stdio.h>
#include <stdlib.h>

// Função para retornar o máximo entre dois valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    // Entrada do usuário
    printf("Digite o numero de itens: ");
    scanf("%d", &n);

    int peso[n], valor[n];

    printf("Digite o peso de cada item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &peso[i]);

    printf("Digite o valor de cada item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &valor[i]);

    printf("Digite a capacidade da mochila: ");
    scanf("%d", &W);

    // Cria tabela DP
    int dp[n + 1][W + 1];

    // Inicializa a primeira linha e coluna com 0
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int w = 0; w <= W; w++)
        dp[0][w] = 0;

    // Preenche a tabela DP
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (peso[i - 1] <= w)
                dp[i][w] = max(valor[i - 1] + dp[i - 1][w - peso[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Valor máximo que pode ser colocado na mochila
    printf("Valor maximo na mochila: %d\n", dp[n][W]);

    // Para recuperar os itens escolhidos
    printf("Itens escolhidos (indices baseados em 0): ");
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i - 1);
            w -= peso[i - 1];
        }
    }
    printf("\n");

    return 0;
}