#include <stdio.h>
#include <math.h>

int BuscaBinaria(int k, int vetor[], int tamDoVetor){
    int esq = 0;
    int dir = tamDoVetor - 1;

    while(esq <= dir){
        int meio = floor((esq + dir)/2);
        if(k == vetor[meio]){
            return meio;
        }

        else if(k > vetor[meio]){
            esq = meio + 1;
        }

        else {
            dir = meio - 1;
        }

    }

    return -1;
}

int main(){
    int tamanho, valor;
    printf("Qual o tamanho do vetor?: ");
    scanf("%d", &tamanho);
    int Vetor[tamanho];

    //preenchimento do vetor
    for(int i = 0; i < tamanho; i++){
       int num;
       printf("O %d valor: ", i + 1);
       scanf("%d", &num);
       Vetor[i] = num;
    }

    printf("Qual o valor a ser procurado no vetor?: ");
    scanf("%d", &valor);

    int indice = BuscaBinaria(valor, Vetor, tamanho);

    if(indice == -1)
       printf("O valor nao se encontra no vetor");
    else{
        printf("O valor %d se encontra no indice %d", valor, indice);
    }

    return 0;
}