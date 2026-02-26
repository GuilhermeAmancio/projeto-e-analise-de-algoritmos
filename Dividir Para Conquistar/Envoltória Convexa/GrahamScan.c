/*A envoltória convexa de um conjunto de pontos no plano é o menor conjunto convexo que 
contém todos esses pontos.*/
//Esse algoritmo está mais otimizado em relação às respostas comparado com o QuickHull

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    double x, y;
} Ponto;

Ponto p0;

//Troca dois pontos
void troca(Ponto *a, Ponto *b) {
    Ponto temp = *a;
    *a = *b;
    *b = temp;
}

//Distância ao quadrado
double dist2(Ponto a, Ponto b) {
    return (a.x - b.x)*(a.x - b.x) +
           (a.y - b.y)*(a.y - b.y);
}

//Orientação
int orientacao(Ponto a, Ponto b, Ponto c) {
    double val = (b.y - a.y)*(c.x - b.x) -
                 (b.x - a.x)*(c.y - b.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2; // 1 = horário, 2 = anti-horário
}

//Comparador para qsort
int compara(const void *vp1, const void *vp2) {
    Ponto *p1 = (Ponto *)vp1;
    Ponto *p2 = (Ponto *)vp2;

    int o = orientacao(p0, *p1, *p2);

    if (o == 0)
        return (dist2(p0, *p2) >= dist2(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void grahamScan(Ponto pontos[], int n) {
    if (n < 3) {
        printf("Fecho convexo não definido (menos de 3 pontos).\n");
        return;
    }

    //1. Ponto mais abaixo (e mais à esquerda em empate)
    int min = 0;
    for (int i = 1; i < n; i++) {
        if ((pontos[i].y < pontos[min].y) ||
           (pontos[i].y == pontos[min].y &&
            pontos[i].x < pontos[min].x))
            min = i;
    }

    troca(&pontos[0], &pontos[min]);
    p0 = pontos[0];

    //2. Ordenar pelo ângulo polar
    qsort(&pontos[1], n-1, sizeof(Ponto), compara);

    //3. Pilha
    Ponto pilha[MAX];
    int topo = 0;

    pilha[topo++] = pontos[0];
    pilha[topo++] = pontos[1];
    pilha[topo++] = pontos[2];

    for (int i = 3; i < n; i++) {
        while (topo >= 2 &&
               orientacao(pilha[topo-2],
                          pilha[topo-1],
                          pontos[i]) != 2) {
            topo--;
        }
        pilha[topo++] = pontos[i];
    }

    //4. Imprimir no mesmo formato
    printf("Fecho Convexo:\n{");
    for (int i = 0; i < topo; i++) {
        printf("(%.2lf,%.2lf)", pilha[i].x, pilha[i].y);
        if (i != topo - 1)
            printf(", ");
    }
    printf("}\n");
}

int main() {
    char entrada[5000];
    Ponto pontos[MAX];
    int n = 0;

    printf("Digite os pontos no formato {(x1,y1), (x2,y2), ...}:\n");
    fgets(entrada, sizeof(entrada), stdin);

    char *ptr = entrada;

    while (*ptr) {
        if (*ptr == '(') {
            ptr++;
            sscanf(ptr, "%lf,%lf", &pontos[n].x, &pontos[n].y);
            n++;
        }
        ptr++;
    }

    grahamScan(pontos, n);

    return 0;
}