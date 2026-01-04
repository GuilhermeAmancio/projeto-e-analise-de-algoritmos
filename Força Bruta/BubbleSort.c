#include <stdio.h>

void BubbleSort(int vetor[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(vetor[j] > vetor[j + 1]){
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void Impressao(int vetor[], int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf(" %d ", vetor[i]);
    }
    printf("]");
}

int main(){
    int tamanho;
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

    BubbleSort(Vetor, tamanho);
    Impressao(Vetor, tamanho);

    return 1;
}