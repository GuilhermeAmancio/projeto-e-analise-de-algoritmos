#include <stdio.h>

//função de busca
int busca(int vetor[], int n, int chave) {
    int i = 0;
    while (i < n && vetor[i] != chave) {
        i++;
    }

    if (i < n)
        return i;
    else
        return -1;
}

int main(){
    int n;
    printf("Qual o tamanho do vetor?: ");
    scanf("%d", &n);
    int vetor[n];

    //preenchimento do vetor
    for(int i = 0; i < n; i++){
       int num;
       printf("O %d valor: ", i + 1);
       scanf("%d", &num);
       vetor[i] = num;
    }

    printf("O valor a ser encontrado no vetor: ");
    int x;
    scanf("%d", &x);

    int posicao = busca(vetor, n, x);
    if(posicao != -1)
    printf("O valor foi encontrado na posicao %d", posicao);
    else
     printf("O valor nao foi encontrado");

    return 1;
}