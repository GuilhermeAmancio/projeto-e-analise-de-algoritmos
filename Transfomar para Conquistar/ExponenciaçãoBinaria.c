/*Algoritmo: Exponenciação Binária
Entrada: Base x, expoente N (não-negativo)
Saida: x^N*/

#include <stdio.h>

double exponenciacaoBinaria(double x, int n) {
    if (n == 0) return 1;
    double resultado = 1;

    double base = x;
    long long expoente = n;

    while (expoente > 0) {
        if (expoente % 2 != 0) {
            resultado = resultado * base;
        }

        base = base * base; //"Elevar ao quadrado"
        expoente = expoente / 2;  // expoente = expoente/2, desloca bits para a direita
    }

    return resultado;
}

int main() {
    int x, n;
    printf("Qual a base?: ");
    scanf("%d", &x);
    printf("Qual o expoente?: ");
    scanf("%d", &n);

    double resultado = exponenciacaoBinaria(x, n);

    printf("Resultado de %d^%d: %.1f\n", x, n, resultado);

    return 0;
}