/*
** Função: Definir uma estrutura que armazenada dados de um empregado. E criar um novo tipo de dados chamado empregado usando a estrutura, onde lá estará um vetor que armazena todos os empregados da empresa.
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data: 20/05/2024  
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_EMPREGADOS 100

// Criação de um novo tipo de dado referenciando a estrutura empregado
typedef struct empregado Empregado;

// Estrutura empregado
struct empregado {
    char nome[50];
    char data_de_nascimento[11];
    char RG[12];
    char data_de_admissao[11];
    float salario;
};

Empregado *cadastrar_empregado() {
    Empregado *empregado = (Empregado *)malloc(sizeof(Empregado));
    if (empregado == NULL) {
            printf("Erro ao alocar memória.\n");
            return NULL;
    }

    printf("Digite o nome completo do empregado: ");
    fgets(empregado->nome, sizeof(empregado->nome), stdin);
    strtok(empregado->nome, "\n");

    printf("Digite a data de nascimento do empregado (dd/mm/aaaa): ");
    fgets(empregado->data_de_nascimento, sizeof(empregado->data_de_nascimento), stdin);
    strtok(empregado->data_de_nascimento, "\n"); 

    printf("Informe o RG do empregado: ");
    scanf("%s", empregado -> RG);
    getchar();

    printf("Informe a data de admissão do empregado (dd/mm/aaaa): ");
    scanf("%s", empregado -> data_de_admissao);

    printf("Informe o salário do empregado: ");
    scanf("%f", &empregado->salario);
    getchar();

    printf("\nCadastro efetuado com sucesso!\n");

    return empregado;
}

// Função para exibir os dados de um empregado
void exibir_empregado(Empregado *empregado) {
    printf("\n--------DADOS DO EMPREGADO---------\n");
    printf("Nome: %s\n", empregado->nome);
    printf("Data de nascimento: %s", empregado->data_de_nascimento);
    printf("\nRG: %s", empregado->RG);
    printf("\nData de admissão: %s", empregado->data_de_admissao);
    printf("\nSalário: R$%.2f\n", empregado->salario);
    printf("-----------------------------------\n");
}

// Função para remover o empregado pelo RG
void remover_empregado(Empregado **vetor_empregados, int *quantidade_empregados, char *rg_empregado) {
    int posicao_empregado = -1;

    // Busca a posição do empregado no vetor
    for (int i = 0; i < *quantidade_empregados; i++) {
        if (strcmp(vetor_empregados[i]->RG, rg_empregado) == 0) {
            posicao_empregado = i;
            break;
        }
    }

    // Verifica se o empregado foi encontrado
    if (posicao_empregado == -1) {
        printf("\nEmpregado não encontrado!\n");
        return;
    }

    // Libera a memória do empregado removido
    free(vetor_empregados[posicao_empregado]);

    // Remove o empregado do vetor
    for (int i = posicao_empregado; i < *quantidade_empregados - 1; i++) {
        vetor_empregados[i] = vetor_empregados[i + 1];
    }

    (*quantidade_empregados)--;
    printf("\nEmpregado removido com sucesso!\n");
}

// Função main
int main() {
    setlocale(LC_ALL, "portuguese");

    // Criação de um vetor de empregados
    Empregado *vetor_empregados[MAX_EMPREGADOS];
    int quantidade_empregados = 0;

    int opcao;

    do {
        printf("\n------ MENU DE OPÇÕES ------\n");
        printf("1 - Cadastrar empregado\n");
        printf("2 - Exibir empregados\n");
        printf("3 - Remover empregado\n");
        printf("4 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                if (quantidade_empregados < MAX_EMPREGADOS) {
                    vetor_empregados[quantidade_empregados] = cadastrar_empregado();
                    quantidade_empregados++;
                } else {
                    printf("Número máximo de empregados atingido.\n");
                }
                break;
            case 2:
                if (quantidade_empregados > 0) {
                    for (int i = 0; i < quantidade_empregados; i++) {
                        exibir_empregado(vetor_empregados[i]);
                    }
                } else {
                    printf("\nNão há empregados cadastrados!\n");
                }
                break;
            case 3:
                if (quantidade_empregados > 0) {
                    char rg_empregado[12];
                    printf("Digite o nome do empregado que deseja remover: ");
                    scanf("%s", rg_empregado);
                    remover_empregado(vetor_empregados, &quantidade_empregados, rg_empregado);
                } else {
                    printf("\nNão há empregados cadastrados!\n");
                }
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 4);

    // Libera a memória alocada para os empregados restantes
    for (int i = 0; i < quantidade_empregados; i++) {
        free(vetor_empregados[i]);
    }

    return 0;
}
