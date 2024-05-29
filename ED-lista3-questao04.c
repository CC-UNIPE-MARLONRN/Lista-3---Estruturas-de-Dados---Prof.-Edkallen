/*
** Função : Escrever um programa que mostre que a afirmação da  Conjectura de Goldbach. Para todo número par entre 700 e 1100, o programa deve imprimir cada número e os primos correspondente que somados resultam naquele número.
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data : 21/05/2024
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//Definir o intervalo de valores para serem exibidos
#define INICIO 700
#define FIM 1100

// Protótipo da função
bool verifica_Primo(int num);
void conj_gold(int n);

// Função para verificar se um número é primo
bool verifica_Primo(int num) {
    if (num <= 1) {
        return false;
    }
    int p;
    for (p = 2; p * p <= num; p++) {
        if (num % p == 0) {
            return false;
        }
    }
    return true;
}

// Função que verifica a Conjectura de Goldbach para números pares
void conj_gold(int n) {
    if (n <= 2 || n % 2 != 0) {
        return;
    }
    int i;
    for (i = 2; i <= n / 2; i++) {
        // Verifica se ambos os números i e (n - i) são primos
        if (verifica_Primo(i) && verifica_Primo(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
        }
    }
}

// Função principal - main()
int main() {
    setlocale(LC_ALL, "Portuguese");

    // Impressão do título
    printf("Conjectura de Goldbach para números pares entre %d e %d:\n", INICIO, FIM);
    int num;
    for (num = INICIO; num <= FIM; num += 2) {
        printf("%d = ", num);

        // Encontrar a soma de dois primos que resulta em num
        int s;
        for (s = 2; s <= num / 2; s++) {
            if (verifica_Primo(s) && verifica_Primo(num - s)) {
                // Imprime a soma dos dois primos e verifica a conjectura para num
                printf("%d + %d\n", s, num - s);
                conj_gold(num);
                break;
            }
        }
    }

    return 0;
}