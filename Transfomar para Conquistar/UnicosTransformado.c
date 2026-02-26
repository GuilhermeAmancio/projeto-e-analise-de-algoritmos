/*Este novo algoritmo segue a lógica de Transformar para Conquistar, mas o objetivo aqui é verificar se todos os elementos de uma lista 
são únicos.
A ideia central é que, ao ordenar a lista, elementos repetidos ficarão obrigatoriamente um ao lado do outro (adjacentes), 
facilitando a verificação.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função de comparação para o qsort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Algoritmo: Unicos_Transformado
bool verificarUnicos(int A[], int n) {
    // Passo 1: Transformação 
    qsort(A, n, sizeof(int), comparar);

    // Passo 2: Verificação de adjacentes 
    for (int i = 0; i <= n - 2; i++) {
        if (A[i] == A[i + 1]) {
            return false; // Encontrou elementos repetidos
        }
    }
    return true; // Todos são únicos
}

int main() {
    int n;

    printf("--- Verificador de Elementos Unicos ---\n");
    printf("Quantos elementos voce deseja inserir na lista? ");
    scanf("%d", &n);

    // Criando o array com o tamanho definido pelo usuário
    int *lista = (int *)malloc(n * sizeof(int));

    if (lista == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

    
    printf("Digite os %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &lista[i]);
    }

    // Execução do algoritmo de transformação
    if (verificarUnicos(lista, n)) {
        printf("Todos os elementos sao unicos.\n");
    } else {
        printf("Existem elementos repetidos.\n");
    }

    // Liberando a memória alocada
    free(lista);

    return 0;
}