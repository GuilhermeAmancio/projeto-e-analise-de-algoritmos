//Dadas duas matrizes quadradas A e B, calcular o produto A x B
#include <stdio.h>

//Função para preencher uma matriz
void CriarMatriz(int n, int m, int matriz[n][m]){
    int valor;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Digite o valor da linha %d e coluna %d\n", i + 1, j + 1);
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }
}

//Função para exibir uma matriz
void MostrarMatriz(int n, int m, int matriz[n][m]){
    for(int i = 0; i < n; i++){
        printf("{ ");
        for(int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("}");
      printf("\n");
    }
}

//Função para realizar o produto de duas matrizes quadradas
 void Produto(int ordem,int matrizA[ordem][ordem], int matrizB[ordem][ordem], int matrizC[ordem][ordem]){
   for(int i = 0; i < ordem; i++){
    for(int j = 0; j < ordem; j++){
        matrizC[i][j] = 0;
        for(int k = 0; k < ordem; k++){
            matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }
   }
 }

int main(){
    int ordem;

 printf("Qual a ordem das matrizes quadradas A e B?\n");
 scanf("%d", &ordem);

 int matrizA[ordem][ordem];
 CriarMatriz(ordem, ordem, matrizA);

 printf("\nMatriz A: \n");
 MostrarMatriz(ordem, ordem, matrizA);

 int matrizB[ordem][ordem];
 CriarMatriz(ordem, ordem, matrizB);

 printf("\nMatriz B: \n");
 MostrarMatriz(ordem, ordem, matrizB);

int matrizC[ordem][ordem];

 Produto(ordem, matrizA, matrizB, matrizC);

 printf("\nMatriz AxB: \n");
 MostrarMatriz(ordem, ordem, matrizC);

 return 0;
}