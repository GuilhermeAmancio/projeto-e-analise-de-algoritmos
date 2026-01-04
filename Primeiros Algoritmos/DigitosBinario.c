//Determinar o número de dígitos necessários para representar o número natural (decimal) em binário
#include <stdio.h>
#include <math.h>

int bin(int dec){
    int cont = 1;
    while (dec > 1){
        cont += 1;
        dec = floor(dec/2);
    }

    return cont;
}

int main(){
    int num;
    printf("Digite um numero decimal: ");
    scanf("%d", &num);

    int resultado = bin(num);

    printf("O numero %d tem %d digitos em sua representacao em binario", num, resultado);

    return 1;
}
