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

void quickSort(int vetor[], int l, int r){
    int s;
    if(l < r){
        s = Particao(vetor, l, r);
        quickSort(vetor, l, s - 1);
        quickSort(vetor, s + 1, r);
    }
}

//Função de impressão (para verificar se o vetor foi ordenado)
void Impressao(int vetor[], int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf(" %d ", vetor[i]);
    }
    printf("]");
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

    quickSort(vetor, l, r);
    Impressao(vetor, n);

    return 0;
}