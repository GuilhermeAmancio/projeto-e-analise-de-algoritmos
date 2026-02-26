//Avaliação de Polinômio pelo Método de Horner
//Entrada: Coeficientes A = [a_N, a_{N-1}, ..., a_0], ponto x
//Saída: Valor de P(x)

#include <stdio.h>

double AvaliacaoPolinomioHorner(double A[], int n, double x) {
    double resultado = A[n];

    for (int i = n - 1; i >= 0; i--) {
        resultado = x * resultado + A[i];
    }
    return resultado;
}

int main() {
    int n;
    double x;

    printf("Avaliacao de Polinomio (Metodo de Horner)\n");
    
    printf("Digite o grau do polinomio (N): ");
    scanf("%d", &n);

    //O vetor precisa ter tamanho N + 1 (ex: grau 3 tem a0, a1, a2, a3)
    double A[n + 1];

    //Leitura dos coeficientes
    printf("Digite os coeficientes do menor para o maior grau (a0 ate aN):\n");
    for (int i = 0; i <= n; i++) {
        printf("Coeficiente a[%d]: ", i);
        scanf("%lf", &A[i]);
    }


    printf("\nDigite o valor de x para avaliacao: ");
    scanf("%lf", &x);

    double valorFinal = AvaliacaoPolinomioHorner(A, n, x);

    printf("\nResultado de P(%.2f) = %.2f\n", x, valorFinal);

    return 0;
}