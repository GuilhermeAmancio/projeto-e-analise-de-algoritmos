//Precisamos realizar K buscas no mesmo conjunto de N elementos

#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Busca Binária para encotrar a primeira ocorrência 
int buscaBinariaPrimeiraOcorrencia(int arr[], int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1;
    int resultado = -1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (arr[meio] == alvo) {
            resultado = meio; // Encontrou, mas continua olhando para a esquerda
            direita = meio - 1; 
        } 
        else if (arr[meio] < alvo) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return resultado;
}

int main() {
    int n, k;

    printf("N (tamanho do conjunto): ");
    if(scanf("%d", &n) != 1) return 1;
    int *conjunto = (int *)malloc(n * sizeof(int));

    printf("Digite o conjunto como [a, b, c, ...]:\n-> ");
    scanf(" ["); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &conjunto[i]);
        if (i < n - 1) scanf(","); 
    }
    scanf("]");

    printf("\nK (quantidade de buscas): ");
    scanf("%d", &k);
    int *valores = (int *)malloc(k * sizeof(int));

    printf("Digite os valores como [x, y, z, ...]:\n-> ");
    scanf(" [");
    for (int i = 0; i < k; i++) {
        scanf("%d", &valores[i]);
        if (i < k - 1) scanf(",");
    }
    scanf("]");

    // Passo 1: Ordenação (Agrupa os repetidos)
    qsort(conjunto, n, sizeof(int), comparar);

    printf("\n--- RESULTADO (CONJUNTO ORDENADO) ---\n");
    printf("[ ");
    for(int i = 0; i < n; i++) printf("%d ", conjunto[i]);
    printf("]\n\n");

    // Passo 2: Buscas
    for (int i = 0; i < k; i++) {
        int res = buscaBinariaPrimeiraOcorrencia(conjunto, n, valores[i]);
        if (res != -1) {
            // Verifica se há mais de um
            int count = 0;
            for(int j = res; j < n && conjunto[j] == valores[i]; j++) count++;
            
            if (count > 1)
                printf("Valor %d: ENCONTRADO %d vezes (inicia no indice %d)\n", valores[i], count, res);
            else
                printf("Valor %d: ENCONTRADO (indice %d)\n", valores[i], res);
        } else {
            printf("Valor %d: NAO ENCONTRADO\n", valores[i]);
        }
    }

    free(conjunto);
    free(valores);
    return 0;
}