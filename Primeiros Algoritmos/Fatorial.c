//Calcular o fatorial de um número N de forma recursiva
#include <stdio.h>

int fatorial(int N){
    if(N == 1 || N == 0)
     return 1;
    else{
        return N*fatorial(N - 1);
    }

}

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    int resultado = fatorial(num);
    printf("O fatorial de %d: %d ", num, resultado);

    return 1;
}