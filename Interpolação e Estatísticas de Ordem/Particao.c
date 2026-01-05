//Particionamento de Lomuto
/*
O pivô fica na posição correta
os elementos à esquerda do pivô são menores do que ele
os elementos à direita do pivô são maiores do que ele
*/
#include <stdio.h>

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

int main(){
    int n, l, r;
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

    int resultado = Particao(vetor, l, r);
    printf("O indice final do pivo: %d", resultado);

    return 0;
}