#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define QUADRADO 2
#define METADE 2
#define TAMANHO_MAXIMO_ENTRADA 5
#define ENCERRAR_PROGRAMA -1
#define INVALIDO -2
#define CONTAGEM_REGRESSIVA 10
#define TEMPO_INTERVALO_CONTAGEM 1
#define STRING_ENCERRAR_PROGRAMA "exit"


enum MenuProgramas{
    SAUDACAO = 1,
    CALCULADORA,
    CONVERSOR_DE_TEMPERATURA,
    FATORIAL,
    MEDIA_ARITMETICA,
    TABUADA,
    DIFERENCAS_ENTRE_COLUNAS,
    DE_100_A_1,
    SUBSTITUIR_CARACTERES,
    TABELA_ASCII,
} ProgramaEscolhido = 0;

char titulosProgramas[][50] = {
        "",
        "Saudação",
        "Calculadora",
        "Conversor de temperatura",
        "Fatorial",
        "Média Aritimética",
        "Tabuada",
        "Diferenças das médias da matriz",
        "Do 1 até o 100 na ordem inversa",
        "Substituir caracteres",
        "Correspondência na tabela ASCCII",
};

/**
 * Academia C/BRM - Accenture
 * ProgramaEscolhido: Cardapio de exercicios
 * 06/01/2022
 *
 * @author Jardel Brandon de Araujo Regis
 * @date 07/01/2022
 * @version 1.0
 * @param   horario  um inteiro representando a hora desejada
 * @return           uma mensagem de saudacao de acordo com a hora fornecida
 */
int main() {
    system("color 1f");
    setlocale(LC_ALL, "Portuguese");

    while(ProgramaEscolhido != ENCERRAR_PROGRAMA) {
        printf("******************************************************************************\n");
        printf("********** Jardel Brandon de Araujo Regis | jardelbrandon@gmail.com **********\n");
        printf("**********         Cardápio de exercícios | %s             **********\n", __DATE__);
        printf("****************************************************************07/01/2022-1.0\n");
        printf("______________________________________________________________________________\n");


        printf("______________________________________________________________________________\n");
        printf("\nCardápio de programas:\n");
        int referencia = 0;
        for(referencia = SAUDACAO; referencia <= TABELA_ASCII; referencia++) {
            printf("\t\t\t %d - %s\n", referencia, titulosProgramas[referencia]);
        }
        printf("\t\t\t exit - Encerrar a execução do programa\n");
        printf("______________________________________________________________________________\n");

        char entradaMenu[TAMANHO_MAXIMO_ENTRADA];
        printf("Digite o valor correspondente ao programa desejado: ");
        scanf("%s", &entradaMenu);
        printf("______________________________________________________________________________\n");

        if(isdigit(entradaMenu[0])) {
            ProgramaEscolhido = atoi(entradaMenu);
        } else if(!strcmp(entradaMenu, STRING_ENCERRAR_PROGRAMA)) {
            ProgramaEscolhido = ENCERRAR_PROGRAMA;
        } else {
            ProgramaEscolhido = INVALIDO;
        }
        switch (ProgramaEscolhido) {
            case SAUDACAO: {
                printf("Seja bem vindo ao Programa %d - %s!\n", SAUDACAO, titulosProgramas[SAUDACAO]);

                printf("Digite seu primeiro nome: ");
                char nome[15];
                scanf("%s", &nome);

                printf("Agora, digite seu sobrenome: ");
                char sobrenome[50];
                scanf(" %[^\n]s", &sobrenome);

                printf("Por fim, digite o ano em que você nasceu (yyyy): ");
                char anoDeNascimento[5];
                scanf("%s", &anoDeNascimento);

                printf("\nSeu nome completo: %s %s\n", nome, sobrenome);

                char dataAtual[] = __DATE__;
                char anoAtual[5];
                strncpy(anoAtual, dataAtual+7, 11);
                printf("Sua idade é/será: %d anos\n", atoi(anoAtual) - atoi(anoDeNascimento));

                printf("Quantidade de caracteres em seu nome: %d \n", strlen(strcat(strcat(nome, " "), sobrenome)));
                break;
            }
            case CALCULADORA: {
                printf("Seja bem vindo ao Programa %d - %s!\n", CALCULADORA, titulosProgramas[CALCULADORA]);

                printf("Insira dois números ao programa: ");
                float numero_1, numero_2;
                scanf("%f %f", &numero_1, &numero_2);

                printf("\nA soma dos números é: %2.f\n", numero_1 + numero_2);
                printf("O produto do primeiro pelo quadrado do segundo é: %2.f\n", numero_1 * pow(numero_2, QUADRADO));
                printf("O quadrado do primeiro número é: %2.f\n", pow(numero_1, QUADRADO));
                printf("A raiz quadrada da soma dos quadrados é: %2.f\n", sqrt(pow(numero_1, QUADRADO) + pow(numero_2, QUADRADO)));
                printf("O seno da diferença do primeiro número pelo segundo é: %2.f\n", sin(numero_1 - numero_2));
                printf("O módulo do primeiro número é: %2.f\n", fabs(numero_1));
                break;
            }
            case CONVERSOR_DE_TEMPERATURA: {
                printf("Seja bem vindo ao Programa %d - %s!\n", CONVERSOR_DE_TEMPERATURA, titulosProgramas[CONVERSOR_DE_TEMPERATURA]);

                printf("Digite o valor da temperatura em graus Fahrenheit: ");
                double grausFahrenheit;
                scanf("%lf", &grausFahrenheit);

                printf("\nO valor da temperatura em graus Celsius é: %2.f\n", (grausFahrenheit - 32.) * (5./9.));
                break;
            }
            case FATORIAL: {
                printf("Seja bem vindo ao Programa %d - %s!\n", FATORIAL, titulosProgramas[FATORIAL]);

                printf("Digite um número para que seja calculado o fatorial: ");
                int numero, i;
                scanf("%d", &numero);

                double fatorial = 1;
                for (i = numero; i > 0; fatorial *= i--);

                printf("\nO fatorial do número informado é: %.0lf\n", fatorial);
                break;
            }
            case MEDIA_ARITMETICA: {
                printf("Seja bem vindo ao Programa %d - %s!\n", MEDIA_ARITMETICA, titulosProgramas[MEDIA_ARITMETICA]);

                const int QUANTIDADE_STRINGS = 10;
                const int QUANTIDADE_CARACTERES = 10;

                printf("Informe %d valores: ", QUANTIDADE_STRINGS);
                char vetorString[QUANTIDADE_STRINGS][QUANTIDADE_CARACTERES];
                int i, somatorio;
                for(i = 0; i < QUANTIDADE_STRINGS; i++) {
                    scanf("%9s", &vetorString[i]);
                }

                printf("\nVetor informado: [ ");
                for(i = 0, somatorio = 0; i < QUANTIDADE_STRINGS; i++) {
                    printf("%s ", vetorString[i]);
                    somatorio += atoi(vetorString[i]);
                }
                printf("]\n");
                printf("Média entre os valores contidos no vetor: %d\n", somatorio / QUANTIDADE_STRINGS);
                break;
            }
            case TABUADA: {
                printf("Seja bem vindo ao Programa %d - %s!\n", TABUADA, titulosProgramas[TABUADA]);

                printf("Tabuada, excluindo a tabuada do 5 \n");

                int multiplicando, multiplicador, produto;
                for(multiplicando = 1; multiplicando <= 10; multiplicando++) {
                    if (multiplicando == 5) continue;
                    printf("Tabuada do %d: \n", multiplicando);
                    for(multiplicador = 1; multiplicador <= 10; multiplicador++) {
                        produto = multiplicando * multiplicador;
                        printf("\t\t %d X %d = %d\n", multiplicando, multiplicador, produto);
                    }
                }
                break;
            }
            case DIFERENCAS_ENTRE_COLUNAS: {
                printf("Seja bem vindo ao Programa %d - %s!\n", DIFERENCAS_ENTRE_COLUNAS, titulosProgramas[DIFERENCAS_ENTRE_COLUNAS]);

                const int QUANTIDADE_LINHAS = 5;
                const int QUANTIDADE_COLUNAS = 3;
                const int COMPLEMENTO_PAR = 1;

                printf("Informe %d valores: ", QUANTIDADE_LINHAS * QUANTIDADE_COLUNAS);
                double matrizValoresInformados[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
                int i, j;
                for(i = 0; i < QUANTIDADE_LINHAS; i++) {
                    for(j = 0; j < QUANTIDADE_COLUNAS; j++) {
                        scanf("%lf", &matrizValoresInformados[i][j]);
                    }
                }

                double somatorioColunasPares = 0;
                double somatorioLinhasImpares = 0;
                printf("Matriz informada: \n");
                for(i = 0; i < QUANTIDADE_LINHAS; i++) {
                    printf(" \t\t ");
                    for(j = 0; j < QUANTIDADE_COLUNAS; j++) {
                        printf("%2.f ", matrizValoresInformados[i][j]);

                        if (!(j % 2)) { // Verifica se a coluna eh par
                            somatorioColunasPares += matrizValoresInformados[i][j];
                        }
                        if (i % 2) { // Verifica se a linha eh impar
                            somatorioLinhasImpares += matrizValoresInformados[i][j];
                        }
                    }
                    printf("\n");
                }

                int quantidadeColunasPares = (((QUANTIDADE_COLUNAS / METADE) + COMPLEMENTO_PAR) * QUANTIDADE_LINHAS);
                int quantidadeLinhasImpares = ((QUANTIDADE_LINHAS / METADE) * QUANTIDADE_COLUNAS);
                double mediaColunasPares = somatorioColunasPares / quantidadeColunasPares;
                double mediaLinhasImpares = somatorioLinhasImpares / quantidadeLinhasImpares;
                printf("Diferença entre a média dos elementos das colunas pares"
                       " e a média dos elementos das linhas ímpares: %.2lf\n",
                       mediaColunasPares - mediaLinhasImpares);
                break;
            }
            case DE_100_A_1: {
                printf("Seja bem vindo ao Programa %d - %s!\n", DE_100_A_1, titulosProgramas[DE_100_A_1]);

                int i;
                for(i = 100; i > 0; i--) {
                    printf("%d\n", i);
                }
                break;
            }
            case SUBSTITUIR_CARACTERES: {
                printf("Seja bem vindo ao Programa %d - %s!\n", SUBSTITUIR_CARACTERES, titulosProgramas[SUBSTITUIR_CARACTERES]);
                printf("O programa realiza a substituição dos caracteres 'a' por 'b'\n");

                printf("Digite uma palavra: ");
                char string[100];
                scanf("%s", &string);

                int contadorCaracter, i;
                for(i = 0, contadorCaracter =0; string[i]; i++) {
                    if(string[i] == 'a') {
                        string[i] = 'b';
                        contadorCaracter++;
                    }

                }

                printf("\nQuantidade de caracteres 'a' modificados: %d\n", contadorCaracter);
                printf("Palavra após troca dos caracteres 'a': %s\n", string);
                break;
            }
            case TABELA_ASCII: {
                printf("Seja bem vindo ao Programa %d - %s!\n", TABELA_ASCII, titulosProgramas[TABELA_ASCII]);

                printf("Digite um caracter: ");
                char caractereDigitado;
                scanf(" %c", &caractereDigitado);

                printf("\nCaracter %c - Código ASCII %d\n", caractereDigitado, caractereDigitado);
                break;
            }
            case ENCERRAR_PROGRAMA: {
                int contadorContagemRegressiva = CONTAGEM_REGRESSIVA;
                while(contadorContagemRegressiva) {
                    printf("Contagem regressiva: %d\n", contadorContagemRegressiva--);
                    int tempoFinal = time(0) + TEMPO_INTERVALO_CONTAGEM;
                    while(time(0) < tempoFinal);
                }
                break;
            }
            default: {
                printf("Opção inválida, tente novamente!");
                break;
            }

        }
        printf("\nFim!\n");
        printf("______________________________________________________________________________\n");
        printf("\nPressione qualquer tecla para continuar. . .\n");
        getch();
        system("cls");
    }


    return 0;
}
