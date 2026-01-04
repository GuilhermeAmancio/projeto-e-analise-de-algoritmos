/*Dada uma string T[0..n - 1], retornar o índica da primeira ocorrência da string P[0..k - 1], com k menor ou igual a n, em T.
Caso não ocorra, retorne -1*/

#include <stdio.h>
#include <string.h>

int StringMatching(int n, int k, char T[], char P[]){
    for(int i = 0; i <= n - k; i++){
        int achou = 1; //nesse caso achou = true

        for(int j = 0; j < k; j++){
            if(T[i + j] != P[j])
            achou = 0; // nesse caso não achou
        }
         if(achou == 1)
         return i;
    }
     return -1;
}

int main(){
    char nome1[80], nome2[80];
    int tam1, tam2;
    printf("Digite uma palavra: ");
    fgets(nome1, 80, stdin);
    nome1[strcspn(nome1, "\n")] = 0;

    printf("Digite uma segunda palavra: ");
    fgets(nome2, 80, stdin);
    nome2[strcspn(nome2, "\n")] = 0;
    tam1 = strlen(nome1);
    tam2 = strlen(nome2);

    int resultado = StringMatching(tam1, tam2, nome1, nome2);

    if(resultado != -1)
      printf("O indice da primeira ocorrencia da segunda string: %d", resultado);
      else{
        printf("Nao houve ocorrencia");
      }

    return 1;
}