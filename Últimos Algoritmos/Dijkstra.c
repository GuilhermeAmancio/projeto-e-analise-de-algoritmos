#include <stdio.h>
#include <limits.h>

#define MAX 100  // número máximo de vértices

// Função para encontrar o vértice com a menor distância que ainda não foi incluído no conjunto SPT
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Função para imprimir as distâncias
void printSolution(int dist[], int n) {
    printf("Vertice \t Distancia da origem\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Implementação do Algoritmo de Dijkstra
void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];    // dist[i] = distância mínima da origem para i
    int sptSet[MAX];  // sptSet[i] = 1 se o vértice i já foi processado

    // Inicializa todas as distâncias como infinito e sptSet como falso
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;  // distância da origem para ela mesma é 0

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;  // marca o vértice como processado

        // Atualiza distâncias dos vértices adjacentes de u
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, n);
}

int main() {
    int n;
    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Digite a matriz de adjacencia (%d x %d), 0 se nao houver aresta:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Digite o vertice de origem: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}