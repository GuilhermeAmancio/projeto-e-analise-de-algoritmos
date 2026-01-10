#include <stdio.h>

//Função de preenchimento de um vetor
void preencheVetor(int vetor[], int n){
    for(int i = 0; i < n; i++){
       int num;
       printf("O %d valor: ", i + 1);
       scanf("%d", &num);
       vetor[i] = num;
    }
}

//Função de Merge
void merge(int v1[], int p, int v2[], int q, int c[]) {
    int i = 0, j = 0;

    //inicializando o vetor c com 0s
    for(int i = 0; i < p + q; i++){
       c[i] = 0;
    }

    while(i < p && j < q){
        if(v1[i] <= v2[j]){
            c[i + j] = v1[i];
            i++;
        }

        else{
            c[i + j] = v2[j];
            j++;
        }
    }

    //copia  elementos restantes de v1 se houver
    while(i < p){
        c[i + j] = v1[i];
        i++;
    }
    
    //copia elementos restantes de v2 se houver
    while(j < q){
        c[i + j] = v2[j];
        j++;
    }
}


void mergeSort(int A[], int n){
    if(n > 1){
        int meio = n/2;
        int n2 = n - meio; //caso o vetor tenha comprimento ímpar (o vetor C terá comprimento ímpar)
        int B[meio];
        //vetor B vai ser igual a A[0..meio - 1]
        for(int i = 0; i < meio; i++){
            B[i] = A[i];
        }

        //vetor C vai ser igual a A[meio..n - 1]
        int C[n2];
        for(int i = meio; i < n; i++){
            C[i- meio] = A[i]; 
        }

        mergeSort(B, meio);
        mergeSort(C, n2);
        merge(B, meio, C, n2, A);
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
    int n; 
    printf("Qual o tamanho do vetor?: ");
    scanf("%d", &n);
    int vetor[n];

    printf("valores do vetor:\n");
    preencheVetor(vetor, n);

    mergeSort(vetor,n);
    printf("O vetor ordenado: \n");
    Impressao(vetor, n);

    return 0;
}