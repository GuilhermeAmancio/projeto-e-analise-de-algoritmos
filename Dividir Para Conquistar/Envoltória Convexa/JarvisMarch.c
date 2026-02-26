#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    double x, y;
} Ponto;

// Função de Orientação (Produto Vetorial)
// 0 = colinear, 2 = anti-horário, 1 = horário
int orientacao(Ponto a, Ponto b, Ponto c) {
    double val = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
    if (val > -1e-9 && val < 1e-9) return 0; // colinear
    return (val > 0) ? 2 : 1; // anti-horário ou horário
}

// Distância ao quadrado entre dois pontos
double dist2(Ponto a, Ponto b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

void jarvisMarch() {
    Ponto pontos[MAX];
    int n = 0;

    printf("==========================================================\n");
    printf("              TESTE DE ENVOLTORIA CONVEXA                 \n");
    printf("==========================================================\n");
    printf("FORMATO ACEITO: {(x1,y1),(x2,y2),...}\n");
    printf("EXEMPLO: {(0,0),(5,5),(10,0),(10,10),(0,10)}\n");
    printf("----------------------------------------------------------\n");
    printf("INSIRA OS PONTOS: ");

    char linha[10000];
    if (!fgets(linha, sizeof(linha), stdin)) {
        printf("Erro na leitura da linha.\n");
        return;
    }

    // Parsing dos pontos
    char *ptr = linha;
    while (*ptr) {
        if (*ptr == '(') {
            ptr++;
            if (sscanf(ptr, "%lf,%lf", &pontos[n].x, &pontos[n].y) == 2) {
                n++;
                if (n >= MAX) break;
            }
        }
        ptr++;
    }

    if (n < 3) {
        printf("\nERRO: São necessários pelo menos 3 pontos para formar uma envoltória.\n");
        return;
    }

    // Jarvis March
    int hull[MAX], hull_size = 0;

    // Ponto mais à esquerda
    int left = 0;
    for (int i = 1; i < n; i++) {
        if (pontos[i].x < pontos[left].x ||
            (pontos[i].x == pontos[left].x && pontos[i].y < pontos[left].y)) {
            left = i;
        }
    }

    int p = left, q;
    do {
        hull[hull_size++] = p;
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            int o = orientacao(pontos[p], pontos[i], pontos[q]);
            if (o == 2) {
                q = i;
            } else if (o == 0 && dist2(pontos[p], pontos[i]) > dist2(pontos[p], pontos[q])) {
                q = i;
            }
        }

        p = q;

    } while (p != left);

    // Saída organizada
    printf("\n----------------------------------------------------------\n");
    printf("ENVOLTORIA CONVEXA RESULTANTE:\n");
    printf("{");
    for (int i = 0; i < hull_size; i++) {
        printf("(%.2lf,%.2lf)", pontos[hull[i]].x, pontos[hull[i]].y);
        if (i != hull_size - 1) printf(",");
    }
    printf("}\n");
    printf("----------------------------------------------------------\n");
}

int main() {
    jarvisMarch();
    return 0;
}