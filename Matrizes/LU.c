#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para imprimir matriz
void imprimirMatriz(double **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Troca de linhas
void trocarLinhas(double **mat, int i, int j, int n) {
    for (int k = 0; k < n; k++) {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

// Fatoração LU com pivoteamento parcial
void fatoracaoLU_Pivot(double **A, double **L, double **U, int *P, int n) {
    // Inicializa P como identidade
    for (int i = 0; i < n; i++) P[i] = i;

    // Inicializa L e U
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            L[i][j] = 0;
            U[i][j] = 0;
        }

    for (int k = 0; k < n; k++) {
        // Pivoteamento parcial
        int maxRow = k;
        for (int i = k + 1; i < n; i++)
            if (fabs(A[i][k]) > fabs(A[maxRow][k]))
                maxRow = i;

        if (maxRow != k) {
            // Troca linhas em A
            trocarLinhas(A, k, maxRow, n);
            // Troca índices em P
            int tmpP = P[k];
            P[k] = P[maxRow];
            P[maxRow] = tmpP;
            // Troca linhas já calculadas de L
            for (int j = 0; j < k; j++) {
                double tmpL = L[k][j];
                L[k][j] = L[maxRow][j];
                L[maxRow][j] = tmpL;
            }
        }

        // Calcula U
        for (int j = k; j < n; j++) {
            double soma = 0;
            for (int s = 0; s < k; s++)
                soma += L[k][s] * U[s][j];
            U[k][j] = A[k][j] - soma;
        }

        // Calcula L
        for (int i = k + 1; i < n; i++) {
            double soma = 0;
            for (int s = 0; s < k; s++)
                soma += L[i][s] * U[s][k];
            L[i][k] = (A[i][k] - soma) / U[k][k];
        }

        L[k][k] = 1; // diagonal de L
    }
}

// Substituição forward Ly = Pb
void forwardSubstitution(double **L, double *b, double *y, int *P, int n) {
    for (int i = 0; i < n; i++) {
        double soma = 0;
        for (int j = 0; j < i; j++)
            soma += L[i][j] * y[j];
        y[i] = b[P[i]] - soma;
    }
}

// Substituição backward Ux = y
void backwardSubstitution(double **U, double *y, double *x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        double soma = 0;
        for (int j = i + 1; j < n; j++)
            soma += U[i][j] * x[j];
        x[i] = (y[i] - soma) / U[i][i];
    }
}

int main() {
    int n;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    // Alocação dinâmica
    double **A = (double **)malloc(n * sizeof(double *));
    double **L = (double **)malloc(n * sizeof(double *));
    double **U = (double **)malloc(n * sizeof(double *));
    int *P = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        L[i] = (double *)malloc(n * sizeof(double));
        U[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Digite os elementos da matriz A (linha por linha):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    // Fatoração LU com pivoteamento
    fatoracaoLU_Pivot(A, L, U, P, n);

    printf("\nMatriz L:\n");
    imprimirMatriz(L, n);
    printf("Matriz U:\n");
    imprimirMatriz(U, n);

    // Resolver Ax = b
    double *b = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    printf("Digite o vetor b:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &b[i]);

    forwardSubstitution(L, b, y, P, n);
    backwardSubstitution(U, y, x, n);

    printf("\nSolucao x:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %8.2f\n", i + 1, x[i]);

    // Liberar memória
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A); free(L); free(U);
    free(P); free(b); free(y); free(x);

    return 0;
}