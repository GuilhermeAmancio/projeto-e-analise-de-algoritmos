#include <stdio.h>

void SelectionSort(int vetor[], int n){
    for(int i = 0; i < n - 1; i++){
        int menor = i;
        for(int j = i + 1; j < n; j++){
            if(vetor[j] < vetor[menor]){
             menor = j;
            }
        }
         int aux = vetor[i];
         vetor[i] = vetor[menor];
         vetor[menor] = aux;
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

    SelectionSort(Vetor, tamanho);
    Impressao(Vetor, tamanho);

    return 0;
}