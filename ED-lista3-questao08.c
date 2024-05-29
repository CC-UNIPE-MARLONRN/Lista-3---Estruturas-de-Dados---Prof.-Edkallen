/* 
** Função:  Criar um TAD (Tipo Abstrato de Dado) para realizar aritmética com números complexos.
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data: 23/05/2024  
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Definição do dado de tipo Complexo
typedef struct complexo Complexo;

// Criação da estrutura do tipo complexo
struct complexo {
    double real;
    double imag;
};

// Função para criar um número complexo
Complexo* criarNumeroComplexo(double part_real, double part_imag) {
    Complexo* novoNumComplexo = (Complexo*)malloc(sizeof(Complexo));
    if (novoNumComplexo != NULL) {
        novoNumComplexo->real = part_real;
        novoNumComplexo->imag = part_imag;
    }
    return novoNumComplexo;
}

// Função para somar dois números complexos
Complexo* somarNumerosComplexos(Complexo* n1, Complexo* n2) {
    Complexo* resultado = criarNumeroComplexo(n1->real + n2->real, n1->imag + n2->imag);
    return resultado;
}

// Função para subtrair dois números complexos
Complexo* subtrairNumerosComplexos(Complexo* n1, Complexo* n2) {
    Complexo* resultado = criarNumeroComplexo(n1->real - n2->real, n1->imag - n2->imag);
    return resultado;
}

// Função para multiplicar dois números complexos
Complexo* multiplicarNumerosComplexos(Complexo* n1, Complexo* n2) {
    Complexo* resultado = criarNumeroComplexo((n1->real * n2->real) - (n1->imag * n2->imag),
                                        (n1->real * n2->imag) + (n1->imag * n2->real));
    return resultado;
}

// Função para dividir dois números complexos
Complexo* dividirNumerosComplexos(Complexo* n1, Complexo* n2) {
    Complexo* resultado = criarNumeroComplexo(((n1->real * n2->real) + (n1->imag * n2->imag)) / ((n2->real * n2->real) + (n2->imag * n2->imag)),
                                        ((n1->imag * n2->real) - (n1->real * n2->imag)) / ((n2->real * n2->real) + (n2->imag * n2->imag)));
    return resultado;
}

// Função para apagar um número complexo
void apagarNumeroComplexo(Complexo *num_complexo) {
    free(num_complexo);
}

// Função para mostrar um número complexo
void mostrarNumeroComplexo(Complexo* complexo) {
    printf("(%.1f + %.1fi)\n", complexo->real, complexo->imag, (complexo->imag >= 0));
}

//Função main
int main() {
    setlocale(LC_ALL, "portuguese");

    int escolha;
    Complexo* n1;
    Complexo* n2;

        printf("\nDigite a parte real do primeiro numero complexo: ");
        double real1;
        scanf("%lf", &real1);
        printf("Digite a parte imaginaria do primeiro numero complexo: ");
        double imag1;
        scanf("%lf", &imag1);
        n1 = criarNumeroComplexo(real1, imag1);

        printf("\nDigite a parte real do segundo numero complexo: ");
        double real2;
        scanf("%lf", &real2);
        printf("Digite a parte imaginaria do segundo numero complexo: ");
        double imag2;
        scanf("%lf", &imag2);
        n2 = criarNumeroComplexo(real2, imag2);

    do {
            printf("\n Número 1: %.1f + %.1fi", real1, imag1);
            printf("\n Número 2: %.1f + %.1fi", real2, imag2);

        printf("\nEscolha a operacao desejada:\n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nSoma: ");
                mostrarNumeroComplexo(somarNumerosComplexos(n1, n2));
                break;
            case 2:
                printf("\nDiferenca: ");
                mostrarNumeroComplexo(subtrairNumerosComplexos(n1, n2));
                break;
            case 3:
                printf("\nProduto: ");
                mostrarNumeroComplexo(multiplicarNumerosComplexos(n1, n2));
                break;
            case 4:
                printf("\nQuociente: ");
                mostrarNumeroComplexo(dividirNumerosComplexos(n1, n2));
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }

    } while (escolha != 5);

       // Liberar memória
        apagarNumeroComplexo(n1);
        apagarNumeroComplexo(n2);

    return 0;
}
