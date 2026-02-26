//Transformar o cálculo do MMC (mais difícil) em um problema de calcular MDC (mais) fácil
//MMC(a, b) = (a*b) / MDC(a, b)
 
#include <stdio.h>

int MDC_Iterativo(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;

}

int MMC(int a, int b){
    int md = MDC_Iterativo(a, b);
    return (a*b)/md;
}

int main(){
    int n1, n2;
    printf("Escolha o primeiro numero: ");
    scanf("%d", &n1);
    printf("Escolha o segundo numero: ");
    scanf("%d", &n2);

    int resultado = MMC(n1, n2);
    printf("O MMC de %d e %d = %d", n1, n2, resultado);


    return 0;
}