#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9

typedef struct {
    double x;
    double y;
} ponto;

/*  Orientação
   > 0  : ponto está à esquerda de AB
   < 0  : ponto está à direita de AB
   = 0  : colinear
*/
double orientacao(ponto a, ponto b, ponto p) {
    return (b.x - a.x) * (p.y - a.y) -
           (b.y - a.y) * (p.x - a.x);
}

double distancia_reta(ponto a, ponto b, ponto p) {
    return fabs(orientacao(a, b, p));
}

//QUICKHULL

void findHull(ponto *pontos, int n, ponto a, ponto b, int lado) {
    int indice_max = -1;
    double dist_max = 0.0;

    for (int i = 0; i < n; i++) {
        double o = orientacao(a, b, pontos[i]);

        if ((lado == 1 && o > EPSILON) ||
            (lado == -1 && o < -EPSILON)) {

            double d = distancia_reta(a, b, pontos[i]);

            if (d > dist_max) {
                indice_max = i;
                dist_max = d;
            }
        }
    }

    if (indice_max == -1)
        return;

    ponto p_max = pontos[indice_max];

    //Recursão esquerda
    findHull(pontos, n, a, p_max, 1);

    //Imprime ponto extremo
    printf("(%.2lf, %.2lf) ", p_max.x, p_max.y);

    //Recursão direita
    findHull(pontos, n, p_max, b, 1);
}

void QuickHull(ponto *pontos, int n) {

    if (n < 3) {
        for (int i = 0; i < n; i++)
            printf("(%.2lf, %.2lf) ", pontos[i].x, pontos[i].y);
        printf("\n");
        return;
    }

    int min_x = 0, max_x = 0;

    for (int i = 1; i < n; i++) {
        if (pontos[i].x < pontos[min_x].x)
            min_x = i;
        if (pontos[i].x > pontos[max_x].x)
            max_x = i;
    }

    printf("\nPontos do Fecho Convexo:\n");

    ponto A = pontos[min_x];
    ponto B = pontos[max_x];

    printf("(%.2lf, %.2lf) ", A.x, A.y);

    //Parte superior 
    findHull(pontos, n, A, B, 1);

    printf("(%.2lf, %.2lf) ", B.x, B.y);

    //Parte inferior 
    findHull(pontos, n, A, B, -1);

    printf("\n");
}

int main() {

    char entrada[4096];
    int capacidade = 10;
    int total = 0;

    ponto *pontos = malloc(capacidade * sizeof(ponto));
    if (!pontos) return 1;

    printf("Forneca os pontos {(x1,y1),(x2,y2)}:\n> ");

    if (!fgets(entrada, sizeof(entrada), stdin)) {
        free(pontos);
        return 1;
    }

    char *ptr = entrada;
    int lidos;

    while (*ptr) {
        if (sscanf(ptr, " (%lf,%lf)%n",
                   &pontos[total].x,
                   &pontos[total].y,
                   &lidos) == 2) {

            total++;
            ptr += lidos;

            if (total >= capacidade) {
                capacidade *= 2;
                ponto *tmp = realloc(pontos,
                                     capacidade * sizeof(ponto));
                if (!tmp) {
                    free(pontos);
                    return 1;
                }
                pontos = tmp;
            }
        } else {
            ptr++;
        }
    }

    if (total > 0)
        QuickHull(pontos, total);
    else
        printf("Nenhum ponto lido corretamente.\n");

    free(pontos);
    return 0;
}