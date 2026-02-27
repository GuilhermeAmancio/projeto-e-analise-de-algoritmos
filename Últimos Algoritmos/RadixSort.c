#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior número do vetor
int getMax(int vetor[], int n) {
    int max = vetor[0];
    for (int i = 1; i < n; i++)
        if (vetor[i] > max)
            max = vetor[i];
    return max;
}

// Função que faz a contagem por dígito (Counting Sort usado internamente)
void countingSort(int vetor[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Conta os dígitos
    for (int i = 0; i < n; i++)
        count[(vetor[i] / exp) % 10]++;

    // Acumula as contagens
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constroi o vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        int digit = (vetor[i] / exp) % 10;
        output[count[digit] - 1] = vetor[i];
        count[digit]--;
    }

    // Copia o vetor de saída para o vetor original
    for (int i = 0; i < n; i++)
        vetor[i] = output[i];
}

// Função principal do Radix Sort
void radixSort(int vetor[], int n) {
    int max = getMax(vetor, n);

    // Aplica Counting Sort para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(vetor, n, exp);
}

int main() {
    int n;

    // Entrada do usuário
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite os %d elementos do vetor (inteiros nao-negativos):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] < 0) {
            printf("Radix Sort nao suporta números negativos nesta versao.\n");
            return 1;
        }
    }

    // Ordena o vetor
    radixSort(vetor, n);

    // Imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}