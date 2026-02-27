#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Função para construir a tabela LPS
void computeLPS(char* padrao, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//Algoritmo KMP
void KMPSearch(char* padrao, char* texto) {
    int M = strlen(padrao);
    int N = strlen(texto);
    int* lps = (int*)malloc(M * sizeof(int));

    computeLPS(padrao, M, lps);

    int i = 0; // índice para texto
    int j = 0; // índice para padrão
    int encontrado = 0;

    while (i < N) {
        if (padrao[j] == texto[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Padrao encontrado no indice %d\n", i - j);
            j = lps[j - 1];
            encontrado = 1;
        } else if (i < N && padrao[j] != texto[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!encontrado) printf("Padrao nao encontrado.\n");
    free(lps);
}

int main() {
    char texto[1000], padrao[100];

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0; // Remove o '\n'

    printf("Digite o padrao a buscar: ");
    fgets(padrao, sizeof(padrao), stdin);
    padrao[strcspn(padrao, "\n")] = 0;

    KMPSearch(padrao, texto);

    return 0;
}