#include <stdio.h>

void InsertionSort(int tamanho, int vetor[]){

    for(int i = 1; i < tamanho; i++){
        int v = vetor[i];
        int j = i - 1;

        while(j >= 0 && v < vetor[j]){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = v;
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

    InsertionSort(tamanho, Vetor);
    Impressao(Vetor, tamanho);

    return 0;
}