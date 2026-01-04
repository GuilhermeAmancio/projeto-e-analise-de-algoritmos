/* Há um conjunto de objetos, cada um com um peso e um valor.
Você tem uma mochila que suporta até X kg.
Escolha os objetos para levar de modo a maximizar o valor

Funciona para entradas pequenas, pois seu crescimento é exponencial
foi necessário usar bitmasking para a combinção dos subconjuntos possíveis
Obs: os nomes dos objetos não podem ter espaços
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


typedef struct Objeto {
    char nome[20];
    int valor;
    int peso;
} objeto;


void MochilaForcaBruta(int peso, objeto itens[], int qnt) {
    
    // Calcula o número total de combinações 
    long long numCombinacoes = 1LL << qnt; 
    
    int valorMax = 0;
    long long melhorMask = 0; // Máscara que representa a melhor combinação

    // Itera por todas as combinações possíveis, de 0 até 2^n - 1
    for (long long i = 0; i < numCombinacoes; i++) {
        
        int pesoTotal = 0;
        int valorTotal = 0;

        // Itera por cada objeto (representado pelo bit 'j')
        for (int j = 0; j < qnt; j++) {
            
            // Verifica se o j-ésimo bit está ligado (1)'
            if ((i >> j) & 1) {
                pesoTotal += itens[j].peso;
                valorTotal += itens[j].valor;
            }
        }

        // Verifica a restrição de capacidade e a otimalidade
        if (pesoTotal <= peso && valorTotal > valorMax) {
            valorMax = valorTotal;
            melhorMask = i; // Salva a máscara da melhor combinação
        }
    }

    //Exibição dos Resultados
    printf("\nResultado (Força Bruta C)\n");
    printf("Valor Máximo: %d\n", valorMax);
    
    printf("Itens Selecionados:\n");
    int pesoFinal = 0;
    
    // Usa a melhor máscara para determinar quais itens foram escolhidos
    for (int j = 0; j < qnt; j++) {
        if ((melhorMask >> j) & 1) {
            printf("  -> %s (Peso: %d, Valor: %d)\n", 
                   itens[j].nome, itens[j].peso, itens[j].valor);
            pesoFinal += itens[j].peso;
        }
    }
    printf("Peso Total: %d\n", pesoFinal);
}


int main() {

    int n;
    printf("Qual a quantidade de objetos?: ");
    scanf("%d", &n);

     int capacidade;
    printf("Qual o peso maximo?: ");
    scanf("%d", &capacidade);


    objeto objetos[n];

    for(int i = 0; i < n; i++){
        printf("Qual o nome do objeto %d?: ", i + 1);
        scanf("%49s", objetos[i].nome);
        printf("Qual o valor do objeto %d?: ", i + 1);
        scanf("%d", &objetos[i].valor);
        printf("Qual o peso do objeto %d?: ", i + 1);
        scanf("%d", &objetos[i].peso);

    }

    
    printf("Capacidade da Mochila: %d\n", capacidade);
    printf("Itens a Considerar:\n");
    for(int i = 0; i < n; i++) {
        printf("  %s: (Valor: %d, Peso: %d)\n", objetos[i].nome, objetos[i].valor, objetos[i].peso);
    }
    
    MochilaForcaBruta(capacidade, objetos, n);

    return 0;
}