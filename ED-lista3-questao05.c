/*
** Função : Escrever um programa que mostre que a afirmação da  Conjectura de Goldbach. O programa deve receber um número de parada do usuário onde deve imprimir a soma dos primos correspondentes entre 2 e o número de parada determinado pelo usuário.
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data : 21/05/2024
** Observações: Estou utilizando a biblioteca <locale.h>, portanto, alguns sinais de acentuação e pontuação podem ser alterados para o uso de sinais mais universais, como a vírgula no lugar do ponto, e a maioria dos acentos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//Definir a constante incial
#define INICIO 2

// Protótipo da função
bool verifica_Primo(int num);
void conj_gold(int n);



// Função para verificar se um número é primo - ela retorna false se não for, mas retorna true se for;
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

// Função void que recebe um número n e calcula os números primos que compõem ele
void conj_gold(int n) {
    if (n <= 2 || n % 2 != 0) {
        return;
    }
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (verifica_Primo(i) && verifica_Primo(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
        }
    }
}

// Função básica - main()
int main() {
    setlocale(LC_ALL, "Portuguese");

    int fim;
    
    //entrada
    printf("Digite o número de parada para o fim da conjuctura: ");
	scanf("%d", &fim); 
    
    // processamento
    printf("Conjectura de Goldbach para números pares entre %d e %d:\n", INICIO, fim);
    int num;
    for (num = INICIO; num <= fim; num += 2) {
        //a conjuctura não pode haver 2, pois não há soma de primos que formem 2;
        if(num == 2){
        	printf("2 = Não há conjuctura de números primos!\n");
		}

        // Encontrar a soma de dois primos
        int s;
        for (s = 2; s <= num / 2; s++) {
            if (verifica_Primo(s) && verifica_Primo(num - s)) {
                conj_gold(num);
                break;
            }
        }
    }

    return 0;
}