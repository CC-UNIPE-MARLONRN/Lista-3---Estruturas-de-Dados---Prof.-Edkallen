/* 
** Função: Criar uma função para ordenar elementos de um vetor usando o "método BubbleSort" (ordenação Bolha). E realizar uma contagem  do números de if's realizados e a quantidade de trocas realizadas.
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data: 23/05/2024  
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Protótipo da Função
void bubbleSort(int [], int, int *, int *);

int main() {
    setlocale(LC_ALL, "portuguese");

    int tamanho_vetor = 10; // tamanho do vetor
    int vetor[tamanho_vetor];

    printf("Ordem atual dos itens no vetor:\n");
    printf("\nVetor {");
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
        printf("%d", vetor[i]);
        if(i != tamanho_vetor - 1) 
            printf(", ");
        else
            printf("}");
    }

    int cont_ifs = 0; 
    int cont_trocas = 0; 

    // Chamando a função bubbleSort para ordenar o vetor
    bubbleSort(vetor, tamanho_vetor, &cont_ifs, &cont_trocas);

    printf("\nVetor ordenado: ");
    printf("\nVetor {");
    for (int i = 0; i < tamanho_vetor - 1; i++) {
        printf("%d, ", vetor[i]);
    }
    printf("%d}", vetor[tamanho_vetor - 1]);

    // Exibir o número de ifs e trocas realizadas
    printf("\n\nNúmero de ifs realizados: %d\n", cont_ifs);
    printf("Número de trocas realizadas: %d\n", cont_trocas);

    return 0;
}

// Função para ordenar um vetor usando o algoritmo Bubble Sort
void bubbleSort(int *vetor, int tamanho_vetor, int *cont_ifs, int *cont_trocas) {
    int i, j, aux;
    for (i = 0; i < tamanho_vetor - 1; i++) {
        for (j = 0; j < tamanho_vetor - i - 1; j++) {
            (*cont_ifs)++; // Incrementa o contador de ifs
            if (vetor[j] > vetor[j + 1]) {
                (*cont_trocas)++; // Incrementa o contador de trocas
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
