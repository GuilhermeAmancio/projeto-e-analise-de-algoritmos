//Computa o enésimo número de Fibonacci recursivamente usando a sua definição
#include <stdio.h>

int Fibonacci(int num){
    if(num <= 1)
    return num;
    else{
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }

}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    int resultado = Fibonacci(n);
    printf("O %d-esimo termo de Fibonacci: %d", n, resultado);

    return 1;
}