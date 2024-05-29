/* 
** Função: Definir uma estrutura em C com o nome de aeroporto. E Definir um vetor de Aeroportos, onde lá estará um vetor que armazena todos os aeroportos.
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data: 20/05/2024  
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_AEROPORTOS 100

// Criação de um novo tipo de dado referenciando a estrutura aeroporto
typedef struct aeroporto Aeroporto;

// Estrutura aeroporto
struct aeroporto {
    char Sigla[3]; 
    char Cidade[50]; 
    char Pais[30];
    float Taxa;
    int Capacidade;
}; 

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastrar Aeroporto
Aeroporto *cadastrar_aeroporto() {
    Aeroporto *aeroporto = (Aeroporto *) malloc(sizeof(Aeroporto));
    if (aeroporto == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    char siglaTemp[4]; // Variável temporária para ler a sigla
    printf("Digite a sigla do Aeroporto (3 caracteres): ");
    while (1) {
        if (scanf("%3s", siglaTemp) == 1) {
            if (strlen(siglaTemp) == 3) {
                memcpy(aeroporto->Sigla, siglaTemp, 3); // Copiar exatamente 3 caracteres
                break;
            }
        }
        limparBuffer(); // Limpa o buffer de entrada
        printf("Sigla inválida. Digite exatamente 3 caracteres: ");
    }
    limparBuffer(); // Limpa o buffer de entrada após a sigla

    printf("Digite a cidade do Aeroporto: ");
    if (fgets(aeroporto->Cidade, sizeof(aeroporto->Cidade), stdin) != NULL) {
        aeroporto->Cidade[strcspn(aeroporto->Cidade, "\n")] = '\0'; // Remove o '\n' se existir
    }

    printf("Digite o País do Aeroporto: ");
    if (fgets(aeroporto->Pais, sizeof(aeroporto->Pais), stdin) != NULL) {
        aeroporto->Pais[strcspn(aeroporto->Pais, "\n")] = '\0'; // Remove o '\n' se existir
    }

    printf("Digite a taxa do Aeroporto: ");
    while (scanf("%f", &aeroporto->Taxa) != 1) {
        limparBuffer(); 
        printf("Entrada inválida. Digite um valor decimal para a taxa: ");
    }
    limparBuffer(); 

    printf("Digite a capacidade do Aeroporto: ");
    while (scanf("%d", &aeroporto->Capacidade) != 1) {
        limparBuffer();
        printf("Entrada inválida. Digite um número inteiro para a capacidade: ");
    }
    limparBuffer();

    printf("Cadastro efetuado com sucesso\n");

    return aeroporto;
}

// Exibir Aeroportos
void exibir_aeroportos(Aeroporto *aeroporto) {
    printf("\n-------- DADOS DO AEROPORTO ---------\n");
    printf("SIGLA: %.3s\n", aeroporto->Sigla); 
    printf("Cidade: %s\n", aeroporto->Cidade);
    printf("País: %s\n", aeroporto->Pais);
    printf("Taxa: %.2f\n", aeroporto->Taxa / 100); // Dividindo por 100 para formatar como porcentagem
    printf("Capacidade: %d\n", aeroporto->Capacidade);
    printf("-------------------------------------\n");
}

// Função para remover o aeroporto pela Sigla
void remover_aeroporto(Aeroporto **vetor_aeroporto, int *quantidade_aeroportos, char *Sigla) {
    int posicao_aeroporto = -1;

    // Busca a posição do aeroporto no vetor
    for (int i = 0; i < *quantidade_aeroportos; i++) {
        if (strncmp(vetor_aeroporto[i]->Sigla, Sigla, 3) == 0) {
            posicao_aeroporto = i;
            break;
        }
    }

    // Verifica se o aeroporto foi encontrado
    if (posicao_aeroporto == -1) {
        printf("\nAeroporto não encontrado!\n\n");
        return;
    }

    // Libera a memória do aeroporto removido
    free(vetor_aeroporto[posicao_aeroporto]);

    // Remove o aeroporto do vetor
    for (int i = posicao_aeroporto; i < *quantidade_aeroportos - 1; i++) {
        vetor_aeroporto[i] = vetor_aeroporto[i + 1];
    }

    (*quantidade_aeroportos)--;
    printf("\nAeroporto removido com sucesso!\n\n");
}

// Função main
int main() {
    setlocale(LC_ALL, "portuguese");
 
    // Criação do vetor de Aeroportos
    Aeroporto *vetor_aeroporto[MAX_AEROPORTOS];
    int aeroportos_cadastrados = 0;

    int opcao = 0;

    // Menu
    do {
        printf("\n------ MENU DE OPÇÕES ------\n");
        printf("1 - Cadastrar aeroporto\n");
        printf("2 - Exibir aeroportos\n");
        printf("3 - Remover aeroporto\n");
        printf("4 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpar o buffer após a leitura da opção

        switch (opcao) {
            case 1:
                if (aeroportos_cadastrados < MAX_AEROPORTOS) {
                    vetor_aeroporto[aeroportos_cadastrados] = cadastrar_aeroporto();
                    if (vetor_aeroporto[aeroportos_cadastrados] != NULL) {
                        aeroportos_cadastrados++;
                        printf("\nAeroporto cadastrado com sucesso!\n");
                    }
                } else {
                    printf("\nCapacidade máxima de aeroportos cadastrados atingida!\n");
                }
                break;
            case 2:
                if (aeroportos_cadastrados > 0) {
                    for (int i = 0; i < aeroportos_cadastrados; i++) {
                        exibir_aeroportos(vetor_aeroporto[i]);
                    }
                } else {
                    printf("\nNão há aeroportos cadastrados!\n");
                }
                break;
            case 3:
                if (aeroportos_cadastrados > 0) {
                    char Sigla[4];
                    printf("Digite a Sigla do aeroporto que deseja remover: ");
                    scanf("%3s", Sigla);
                    limparBuffer(); // Limpar o buffer após a leitura da sigla
                    remover_aeroporto(vetor_aeroporto, &aeroportos_cadastrados, Sigla);
                } else {
                    printf("\nNão há aeroportos cadastrados!\n");
                }
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcao != 4);

    // Libera a memória alocada para os aeroportos restantes
    for (int i = 0; i < aeroportos_cadastrados; i++) {
        free(vetor_aeroporto[i]);
    }

    return 0;
}
