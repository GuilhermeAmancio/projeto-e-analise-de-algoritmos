//Algoritmo de Karatsuba para multiplicação de dois números grandes

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função auxiliar para remover zeros à esquerda
void remove_zeros(char* str) {
    int i = 0, j = 0;
    while (str[i] == '0' && str[i+1] != '\0') i++;
    if (i > 0) {
        while (str[i] != '\0') str[j++] = str[i++];
        str[j] = '\0';
    }
}

void preenche_metades(int n, char n1[], char n2[], char esqx[], char dirx[], char esqy[], char diry[]) {
    int m = n / 2;
    int tamanho_esq = n - m; // parte alta
    int tamanho_dir = m;     // parte baixa

    // Metade esquerda (High)
    strncpy(esqx, n1, tamanho_esq);
    esqx[tamanho_esq] = '\0';
    strncpy(esqy, n2, tamanho_esq);
    esqy[tamanho_esq] = '\0';

    // Metade direita (Low)
    strcpy(dirx, n1 + tamanho_esq);
    strcpy(diry, n2 + tamanho_esq);
}

// Soma duas strings numéricas
void soma_strings(char num1[], char num2[], char resultado[]) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int k = 0;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? num1[i--] - '0' : 0;
        int d2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = d1 + d2 + carry;
        resultado[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    resultado[k] = '\0';

    // Inverte a string resultante
    for (int idx = 0; idx < k / 2; idx++) {
        char tmp = resultado[idx];
        resultado[idx] = resultado[k - 1 - idx];
        resultado[k - 1 - idx] = tmp;
    }
    remove_zeros(resultado);
}

// Subtração de strings: num1-num2, num1>=num2
void subtrai_strings(char num1[], char num2[], char resultado[]) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int k = 0;
    int borrow = 0;

    while (i >= 0) {
        int d1 = num1[i--] - '0';
        int d2 = (j >= 0) ? num2[j--] - '0' : 0;
        int diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;
        resultado[k++] = diff + '0';
    }
    resultado[k] = '\0';

    for (int idx = 0; idx < k / 2; idx++) {
        char tmp = resultado[idx];
        resultado[idx] = resultado[k - 1 - idx];
        resultado[k - 1 - idx] = tmp;
    }
    remove_zeros(resultado);
}

// Multiplica string num por 10^n (deslocamento)
char* multiplica10(char* num, int n) {
    if (strcmp(num, "0") == 0) return strdup("0");
    int len = strlen(num);
    char* res = malloc(len + n + 1);
    strcpy(res, num);
    for (int i = 0; i < n; i++) res[len + i] = '0';
    res[len + n] = '\0';
    return res;
}

// Multiplica pequenas strings diretamente (caso base)
char* mult_simples(char* num1, char* num2) {
    int n1 = strlen(num1), n2 = strlen(num2);
    int maxn = n1 + n2;
    int *res = (int*)calloc(maxn, sizeof(int));
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (int i = maxn - 1; i > 0; i--) {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }
    char* resultado = malloc(maxn + 1);
    for (int i = 0; i < maxn; i++) resultado[i] = res[i] + '0';
    resultado[maxn] = '\0';
    free(res);
    remove_zeros(resultado);
    return resultado;
}

char* karatsuba(int n, char n1[], char n2[]) {
    if (n <= 2) return mult_simples(n1, n2); // caso base para até 2 dígitos

    int m = n / 2;
    int tamanho_esq = n - m;
    int tamanho_dir = m;

    char esqx[tamanho_esq + 1], dirx[tamanho_dir + 1];
    char esqy[tamanho_esq + 1], diry[tamanho_dir + 1];

    preenche_metades(n, n1, n2, esqx, dirx, esqy, diry);

    char* A = karatsuba(tamanho_esq, esqx, esqy);
    char* B = karatsuba(tamanho_dir, dirx, diry);

    char soma1[tamanho_esq + 2], soma2[tamanho_esq + 2];
    soma_strings(esqx, dirx, soma1);
    soma_strings(esqy, diry, soma2);
    
    // Chamada recursiva para C = (esqx+dirx)*(esqy+diry)
    int max_soma = strlen(soma1) > strlen(soma2) ? strlen(soma1) : strlen(soma2);
    char* C = karatsuba(max_soma, soma1, soma2);

    // z1 = C - A - B
    char* temp2 = malloc(strlen(C) + 2);
    subtrai_strings(C, A, temp2);
    char* C_minus_AB = malloc(strlen(temp2) + 2);
    subtrai_strings(temp2, B, C_minus_AB);
    free(temp2);

    char* A_shift = multiplica10(A, 2 * tamanho_dir);
    char* C_shift = multiplica10(C_minus_AB, tamanho_dir);

    char* temp = malloc(strlen(A_shift) + strlen(C_shift) + 2);
    soma_strings(A_shift, C_shift, temp);

    char* resultado_final = malloc(strlen(temp) + strlen(B) + 2);
    soma_strings(temp, B, resultado_final);

    free(A); free(B); free(C); free(C_minus_AB); free(A_shift); free(C_shift); free(temp);
    return resultado_final;
}

int main() {
    int n;
    printf("Qual o tamanho dos dois numeros a serem multiplicados?: ");
    scanf("%d", &n);
    char num1[n + 1], num2[n + 1];

    printf("Digite o primeiro numero: ");
    scanf("%s", num1);
    printf("Digite o segundo numero: ");
    scanf("%s", num2);

    // Ajuste para garantir que n reflita o maior tamanho real
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    n = (len1 > len2) ? len1 : len2;

    // Normalização com zeros à esquerda
    char num1_p[n + 1], num2_p[n + 1];
    memset(num1_p, '0', n); num1_p[n] = '\0';
    memset(num2_p, '0', n); num2_p[n] = '\0';
    strcpy(num1_p + (n - len1), num1);
    strcpy(num2_p + (n - len2), num2);

    char* resultado = karatsuba(n, num1_p, num2_p);
    printf("Resultado: %s\n", resultado);
    free(resultado);
    return 0;
}