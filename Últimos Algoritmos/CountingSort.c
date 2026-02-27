#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    // Solicita os elementos do vetor
    printf("Digite os %d elementos do vetor (inteiros nao-negativos):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] < 0) {
            printf("Counting Sort nao suporta numeros negativos.\n");
            return 1;
        }
    }

    // Encontra o valor máximo para definir o tamanho do vetor auxiliar
    int max = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > max)
            max = vetor[i];
    }

    // Cria e inicializa o vetor de contagem
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Conta as ocorrências de cada elemento
    for (int i = 0; i < n; i++)
        count[vetor[i]]++;

    // Reconstrói o vetor ordenado
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            vetor[index++] = i;
            count[i]--;
        }
    }

    // Imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}