//Determinar se os valores de um vetor são distintos entre si 
#include <stdio.h>

//função para ver se todos os elemetos de um vetor são únicos
int Distintos(int vetor[], int n){

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(vetor[i] == vetor[j])
            return -1;
        }
    }

 return 1;
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

    int resultado = Distintos(vetor,n);

    if(resultado != -1){
    printf("Todos os elementos distintos");
    }
    else{
        printf("Existe algum elemento que se repete");
    }
     
    return 1;
}