/*
Em um conjunto de dados a k-ésima estatística de ordem é o k-ésimo menor valor
*/

#include <stdio.h>

//Função de partição
int Particao(int vetor[], int l, int r){
    int v = vetor[l];
    int s = l;
    int aux1, aux2;

    for(int i = l + 1; i <= r; i++ ){
        if(vetor[i] < v){
            s = s + 1;
            aux1 = vetor[s];
            vetor[s] = vetor[i];
            vetor[i] = aux1;
        }
    }

    aux2 = vetor[s];
    vetor[s] = vetor[l];
    vetor[l] = aux2;

    return s;
}

int estatisticaOrdem(int vetor[], int l, int r, int k){
    int s = Particao(vetor, l, r );

    //se o intervalo tiver apenas um elemento
    if (l == r) return vetor[l];

    if(s == k - 1){
        return vetor[s];
    }
    else if(s > k - 1){
        return estatisticaOrdem(vetor, l, s - 1, k);
    }
    else{
        return estatisticaOrdem(vetor, s + 1, r, k );
    }
}

int main(){
    int n, l, r, k;
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

    printf("Qual o indice da esquerda da particao?: ");
    scanf("%d", &l);
    printf("Qual o indice da direita da particao?: ");
    scanf("%d", &r);
    printf("Qual o elemento do vetor que voce deseja escolher?: ");
    scanf("%d", &k);

    int resultado = estatisticaOrdem(vetor, l, r, k);
    printf("O valor encontrado para a %d-esima estatistica de ordem e: %d\n", k, resultado);

    return 0;
}