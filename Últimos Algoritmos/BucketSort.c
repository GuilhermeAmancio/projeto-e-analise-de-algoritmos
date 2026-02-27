#include <stdio.h>
#include <stdlib.h>

// Função para ordenar um balde usando insertion sort
void insertionSort(int bucket[], int n) {
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
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
            printf("Bucket Sort nao suporta numeros negativos nesta versao.\n");
            return 1;
        }
    }

    // Encontra o valor máximo
    int max = vetor[0];
    for (int i = 1; i < n; i++)
        if (vetor[i] > max)
            max = vetor[i];

    // Define o número de buckets (uma boa heurística é n)
    int bucketCount = n;
    int* buckets[bucketCount];
    int bucketSizes[bucketCount];
    int bucketCapacities[bucketCount];

    // Inicializa os buckets
    for (int i = 0; i < bucketCount; i++) {
        bucketCapacities[i] = 5; // capacidade inicial
        buckets[i] = (int*) malloc(bucketCapacities[i] * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int idx = (vetor[i] * bucketCount) / (max + 1);
        if (bucketSizes[idx] >= bucketCapacities[idx]) {
            bucketCapacities[idx] *= 2;
            buckets[idx] = (int*) realloc(buckets[idx], bucketCapacities[idx] * sizeof(int));
        }
        buckets[idx][bucketSizes[idx]++] = vetor[i];
    }

    // Ordena cada bucket e concatena no vetor original
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                vetor[index++] = buckets[i][j];
            }
        }
        free(buckets[i]);
    }

    // Imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}