/*O algoritmo utiliza a estratégia de transformação para resolver um problema estatístico: 
encontrar a Moda (o valor que mais se repete em um conjunto).

Ao ordenar a lista, todos os valores iguais ficam grudados, o que nos permite contar as frequências com uma única passada pelo vetor.*/

#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void analisarModaCompleta(int A[], int n) {
    if (n <= 0) return;

    //Passo 1: Transformação (Ordenação) 
    qsort(A, n, sizeof(int), comparar);

    //Passo 2: Descobrir qual é a maior frequência existente 
    int freq_max = 0;
    int freq_atual = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i-1]) {
            freq_atual++;
        } else {
            if (freq_atual > freq_max) freq_max = freq_atual;
            freq_atual = 1;
        }
    }
    if (freq_atual > freq_max) freq_max = freq_atual;

    //Passo 3: Analisar resultados
    if (freq_max == 1 && n > 1) {
        printf("\nNao ha moda (todos os elementos aparecem apenas uma vez).\n");
    } else {
        printf("\nMaior frequencia encontrada: %d vez(es).\n", freq_max);
        printf("Valor(es) da(s) moda(s): ");
        
        //Segunda passada para imprimir todos que empatam no topo
        freq_atual = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && A[i] == A[i-1]) {
                freq_atual++;
            } else {
                if (freq_atual == freq_max) {
                    printf("%d ", A[i-1]);
                }
                freq_atual = 1;
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Quantos elementos tem  a lista? ");
    scanf("%d", &n);

    int *conjunto = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &conjunto[i]);
    }

    analisarModaCompleta(conjunto, n);

    free(conjunto);
    return 0;
}