//Dado um conjunto de pontos, encontrar o par tal que a distância entre eles seja menor que a de qualquer outro par
//Os pontos estão na forma X_ab, em que a é a a-ésima coordenada do b-ésimo ponto
#include <stdio.h>
#include <math.h>

void fazerPontos(int dimensao, int quantDePontos, int vetor[quantDePontos][dimensao]){
    int num;

  for(int i = 0; i < quantDePontos; i++){
    for(int j = 0; j < dimensao; j++){
        printf("O valor da coordenada X_%d%d: ",j + 1, i + 1);
        scanf("%d", &num);
        vetor[i][j] = num;
    }
  }
}

void MaisProximos(int dim, int numDePontos, int Ponto[numDePontos][dim]){
    int par[2] = {0, 0};
    float menor = 1.0f / 0.0f; //Cria um infinito positivo

    for(int i = 0; i < numDePontos - 1; i++){
        for(int j = i + 1; j < numDePontos; j++){
            double dist = 0;
            for(int k = 0; k < dim; k++){
                dist = (Ponto[i][k] - Ponto[j][k])*(Ponto[i][k] - Ponto[j][k]) + dist;
            }
            dist = sqrt(dist);

            if(dist < menor){
                menor = dist;
                par[0] = i;
                par[1] = j;
            }
        }
    }

    printf("Os pontos mais proximos: %d e %d\nCom distancia: %.4f", par[0] + 1, par[1] + 1, menor);

}

int main(){
    int d, num;
    printf("Qual a dimensao dos pontos?: ");
    scanf("%d", &d);
    printf("Qual o numero de pontos?: ");
    scanf("%d", &num);
    int pontos[num][d];

    fazerPontos(d, num, pontos);
    MaisProximos(d, num, pontos);


    return 0;
}