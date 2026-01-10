//Dado dois vetores ordenados v1 e v2, produz um vetor c ordenado contendo todos os elementos de v1 e v2
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

//Função de impressão (para verificar se o vetor foi ordenado)
void Impressao(int vetor[], int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf(" %d ", vetor[i]);
    }
    printf("]");
}


int main(){
    int n1, n2; 
    printf("Qual o tamanho do primeiro vetor?: ");
    scanf("%d", &n1);
    int vetor1[n1];
    printf("Qual o tamanho do segundo vetor?: ");
    scanf("%d", &n2);
    int vetor2[n2];

    printf("valores do segundo vetor: ");
    preencheVetor(vetor1, n1);
    printf("valores do segundo vetor: ");
    preencheVetor(vetor2, n2);

    int tam_c = n1 + n2;

    int c[tam_c];
    merge(vetor1, n1, vetor2, n2, c);
    Impressao(c, tam_c);

    return 0;
}