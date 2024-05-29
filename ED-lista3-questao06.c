/* 
** Função: Criar um algoritmo que aplica o método de Newton-Raphsonem em uma função para calcular a raiz quadrada de um número n com aproximação de 0.0001;
** Autor: Marlon Rufino do nascimento 2º período turma A 2024.1
** Data: 21/05/2024  
** Observações: Estou utilizando a função 'setlocale' da biblioteca 'locale.h' para a representação de acentuação padrão da lingua portuguesa, tais como ´, ^, `, ª ...  
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define APROX 0.0001

// Protótipo da função
float calcula_raiz_Newton_raphonem(float, float);

int main() {
    setlocale(LC_ALL, "portuguese");

    float n;

    printf("Digite o valor de n: ");
    scanf("%f", &n);

    printf("A raiz aproximada de %.1f é: %.4f\n", n, calcula_raiz_Newton_raphonem(n, APROX));

    return 0;
}

float calcula_raiz_Newton_raphonem(float n, float aproximacao) {
    float raiz_newton_raphonem = n;

    while (1) {
        float proxima_aproximacao = (raiz_newton_raphonem + (n / raiz_newton_raphonem)) / 2;

        if (fabs(proxima_aproximacao - raiz_newton_raphonem) < aproximacao)
            break;

        raiz_newton_raphonem = proxima_aproximacao;
    }

    return raiz_newton_raphonem;
}
