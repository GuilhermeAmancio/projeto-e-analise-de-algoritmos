//Achar o máximo de um vetor de números

#include <stdio.h>

//função para achar o máximo
int Maximo(int vetor[],int n){
   int max = vetor[0];
   for(int i = 1; i < n; i++){
     if(vetor[i] > max)
     max = vetor[i];
   }
   return max;
}


int main(){
    int num;
    printf("Qual o tamanho do vetor?: ");
    scanf("%d", &num);
    int Vetor[num];

    //preenchimento do vetor
    for(int i = 0; i < num; i++){
       int num;
       printf("O %d valor: ", i + 1);
       scanf("%d", &num);
       Vetor[i] = num;
    }

    int Max = Maximo(Vetor, num);
    printf("O valor maximo desse vetor: %d", Max);

    return 1;
}