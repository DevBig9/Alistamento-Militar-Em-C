#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char name[50];
    int idade;
    float altura;
    int opcao1, opcao2;
    int data_nascimento;
    int idade_atual;

    printf("+-----------------------+\n");
    printf("   ALISTAMENTO MILITAR   \n");
    printf("+-----------------------+\n");

    printf("Ola, seja bem-vindo!!!\n");
    printf("Esse e o sistema de Alistamento Militar do Exercito Brasileiro.\n");
    printf("Responda as perguntas abaixo!\n");

    printf("Digite seu ano de nascimento (AAAA): ");
    scanf("%d", &data_nascimento);
    
    idade_atual = 2025 - data_nascimento;

    if (idade_atual >= 18) {
        printf("Voce ja pode se alistar!\n");
    } else {
        printf("Voce e menor de 18 anos e ainda nao pode se alistar\n");
        exit(0);
    }
        
        printf("Continue com o alistamento abaixo! \n");

    while (1) {
        printf("Voce deseja servir?\n");
        printf("Digite (1) se quiser servir! E (2) se nao quiser servir!\n");

        if (scanf("%d", &opcao1) == 1 && (opcao1 == 1 || opcao1 == 2)) {
            break;
        } else {
            printf("Opçao invalida! Digite 1 ou 2.\n");
            while (getchar() != '\n'); 
        }
    }

    if (opcao1 == 1) {
        printf("+-----------------------+\n");
        printf("   ALISTAMENTO MILITAR   \n");
        printf("+-----------------------+\n");

        printf("Ficamos felizes em saber que voce deseja servir conosco!\n");
        printf("Digite os dados conforme solicitado abaixo para preencher seu cadastro.\n");

        while (1) {
            while (getchar() != '\n');  

            printf("\nDigite seu nome completo: ");
            fgets(name, sizeof(name), stdin); 
            name[strcspn(name, "\n")] = '\0';

            printf("\nDigite sua idade: ");
            if (scanf("%d", &idade) != 1) {
                printf("Idade invalida. Digite um numero inteiro.\n");
                while (getchar() != '\n');
                continue;
            }

            printf("\nDigite sua altura (em metros ou centimetros): ");
            if (scanf("%f", &altura) != 1 || altura <= 0) {
                printf("Altura invalida. Digite um numero positivo valido.\n");
                while (getchar() != '\n');
                continue;
            }

           
            if (altura > 10) {
                altura = altura / 100.0;
            }

            printf("\nSeus dados sao: \n");
            printf("Seu nome e: %s\n", name);
            printf("Sua idade atual e: %d\n", idade);
            printf("Voce tem: %.2f metros de altura!\n", altura);

            printf("\nDigite (1) para confirmar se seus dados estao corretos:\n");
            printf("Digite (2) para dizer se seus dados estao incorretos:\n");

            if (scanf("%d", &opcao2) == 1) {
                if (opcao2 == 1) {
                    printf("Parabens! Voce esta alistado.\n");
                    break;
                } else if (opcao2 == 2) {
                    printf("Por favor, digite novamente seus dados.\n");
                    continue;
                } else {
                    printf("Opçao invalida! Digite 1 ou 2.\n");
                }
            } else {
                printf("Opçao invalida! Digite 1 ou 2.\n");
                while (getchar() != '\n');
            }
        }
    } else {
        printf("Infelizmente voce nao vai ter a honra de servir ao nosso Exercito Brasileiro!\n");
    }

    return 0;
}
