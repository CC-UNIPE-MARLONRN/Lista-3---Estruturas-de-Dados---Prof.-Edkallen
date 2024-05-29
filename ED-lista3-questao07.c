/* 
** Função: Implementar uma função que classifica os elementos de um vetor em ordem crescente usando o algoritmo “quicksort”;
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data: 22/05/2024  
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Protótipos das funções
void quicksort(int *, int, int);
int separa_metade(int *, int, int);

int main(){
    setlocale(LC_ALL, "portuguese");

    int tamanho_vetor = 10; // Tamanho do vetor
    int vetor[tamanho_vetor];

    printf("Vetor original: ");
    printf("\nVetor {");
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
        printf("%d", vetor[i]);
        if(i != tamanho_vetor - 1) 
            printf(", ");
        else
            printf("}");
    }

    // Chamando a função quicksort para ordenar o vetor
    quicksort(vetor, 0, tamanho_vetor - 1);

    printf("\nVetor ordenado: ");
    printf("\nVetor {");
    for (int i = 0; i < tamanho_vetor - 1; i++) {
        printf("%d, ", vetor[i]);
    }
    printf("%d}", vetor[tamanho_vetor - 1]);

    return 0;
}

void quicksort(int *vetor, int inicio, int fim){
    int meio;
    if(fim > inicio){
        meio = separa_metade(vetor, inicio, fim);
        quicksort(vetor, inicio, meio - 1);
        quicksort(vetor, meio + 1, fim);
    }
}

int separa_metade(int *vetor, int inicio, int fim){
    int meio = vetor[inicio];
    int esq = inicio + 1;
    int dir = fim;
    int aux;

    while (esq <= dir) {
        while (esq <= fim && vetor[esq] <= meio)
            esq++;       //Avança a posição da esquerda
        while (dir > inicio && vetor[dir] > meio)
           dir--;        //Recua a posição da direita
        if (esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir]; //trocam de lado - esquerda e direita
            vetor[dir] = aux;
        }
    }
    aux = vetor[dir];
    vetor[dir] = vetor[inicio];
    vetor[inicio] = aux;
    return dir;
}
