/**
 * @file menu.c
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @brief Arquivo contndo as implementacoes das definicoes do programas_auxiliares.h
 */

#include "programas_auxiliares.h"

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao responsavel por receber a entrada informada
 *          pelo usuario no terminal referente ao item escolhido
 * @return  entradaMenu retorna a string informada
 */
char* receberOpcaoEscolhidaDoMenu() {
    char entradaMenu[TAMANHO_MAXIMO_ENTRADA];
    printf("Digite o valor correspondente ao programa desejado: ");
    scanf("%s", &entradaMenu);
    printf("______________________________________________________________________________\n");
    return (char*) entradaMenu;
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que realiza a validacao da entrada do usuario
 *          destinando para os possiveis caminhos, que sao
 *          uma entrada valida - executa o programa
 *          uma entrada invalida - repete o recebimento da entrada
 *          uma entrada de saida - encerrar o programa
 * @param entrada char para o tratamento
 * @return  MenuProgramas  saida tratada
 */
int validarEntrada(char *entrada) {
    if(isdigit(entrada[0])) {
        return atoi(entrada);
    } else if(!strcmp(entrada, STRING_ENCERRAR_PROGRAMA)) {
        return ENCERRAR_PROGRAMA;
    } else {
        return INVALIDO;
    }
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que imprime nome completo idade e caracteres do nome informados
 * @param   nome idade
 */
void imprimirSaudacao(char *nome, int idade) {
    printf("\nSeu nome completo: %s \n", nome);
    printf("Sua idade é/será: %d anos\n", idade);
    printf("Quantidade de caracteres em seu nome: %d \n", strlen(nome));
    printf("Quantidade de caracteres em seu nome (+) sua idade: %d \n", strlen(nome) + idade);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que faz o tratamento das entradas para o programa saudacao
 */
void programaSaudacao() {
    printf("Seja bem vindo ao Programa %d - %s!\n", SAUDACAO, titulosProgramas[SAUDACAO]);

    printf("Digite seu primeiro nome: ");
    char nome[TAMANHO_MAXIMO_ENTRADA_NOME];
    scanf("%s", &nome);

    printf("Agora, digite seu sobrenome: ");
    char sobrenome[TAMANHO_MAXIMO_ENTRADA_NOME];
    scanf(" %[^\n]s", &sobrenome);

    printf("Por fim, digite o ano em que você nasceu (yyyy): ");
    char anoDeNascimento[TAMANHO_MAXIMO_ENTRADA];
    scanf("%s", &anoDeNascimento);

    char dataAtual[] = __DATE__;
    char anoAtual[5];
    strncpy(anoAtual, dataAtual+7, 11);
    int idade = atoi(anoAtual) - atoi(anoDeNascimento);
    char* nomeCompleto = strcat(strcat(nome, " "), sobrenome);

    imprimirSaudacao(nomeCompleto, idade);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao retorna o valor da soma de dois numeros
 * @param   x y
 * @return  soma
 */
int somaInteiro(float* x, float* y) {
    return *x + *y;
}


/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que realiza calculos com dois numeros informados pelo usuario
 */
void programaCalculadora() {
    printf("Seja bem vindo ao Programa %d - %s!\n", CALCULADORA, titulosProgramas[CALCULADORA]);

    printf("Insira dois números ao programa: ");
    float numero_1, numero_2;
    scanf("%f %f", &numero_1, &numero_2);

    printf("\nA soma dos números é (inteiro): %d\n", somaInteiro(&numero_1, &numero_2));
    printf("O produto do primeiro pelo quadrado do segundo é: %2.f\n", numero_1 * pow(numero_2, QUADRADO));
    printf("O quadrado do primeiro número é: %2.f\n", pow(numero_1, QUADRADO));
    printf("A raiz quadrada da soma dos quadrados é: %2.f\n", sqrt(pow(numero_1, QUADRADO) + pow(numero_2, QUADRADO)));
    printf("O seno da diferença do primeiro número pelo segundo é: %2.f\n", sin(numero_1 - numero_2));
    printf("O módulo do primeiro número é: %2.f\n", fabs(numero_1));
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que converte a temperatura de Fahrenheit para Celsius
 */
void programaConversorDeTemperatura() {
    printf("Seja bem vindo ao Programa %d - %s!\n", CONVERSOR_DE_TEMPERATURA, titulosProgramas[CONVERSOR_DE_TEMPERATURA]);

    printf("Digite o valor da temperatura em graus Fahrenheit: ");
    double grausFahrenheit;
    scanf("%lf", &grausFahrenheit);

    printf("\nO valor da temperatura em graus Celsius é: %2.f\n", (grausFahrenheit - 32.) * (5./9.));
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que imprime o fatorial do numero informado
 */
void programaFatorial() {
    printf("Seja bem vindo ao Programa %d - %s!\n", FATORIAL, titulosProgramas[FATORIAL]);

    printf("Digite um número para que seja calculado o fatorial: ");
    int numero, i;
    scanf("%d", &numero);

    double fatorial = 1;
    for (i = numero; i > 0; fatorial *= i--);

    printf("\nO fatorial do número informado é: %.0lf\n", fatorial);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que cria uma matriz da tabuada da multiplicacao, retirando a do 5
 * @return  matrizTabuada
 */
short unsigned int** programaTabuada() {
    printf("Seja bem vindo ao Programa %d - %s!\n", TABUADA, titulosProgramas[TABUADA]);

    printf("Tabuada, excluindo a tabuada do 5 \n");

    short unsigned int **matrizTabuada = (int **) malloc(QUANTIDADE_OPERACOES_TABUADA * sizeof(short unsigned int*));
    if (matrizTabuada == NULL) {
        printf("\nError na alocação de memória!\n*Encerrando programa*\n");
        exit(0);
    }
    int multiplicando, multiplicador, produto;
    for(multiplicando = INICIO_OPERACOES_TABUADA; multiplicando <= QUANTIDADE_OPERACOES_TABUADA; multiplicando++) {
        if (multiplicando == 5)
            continue;
        printf("Tabuada do %d: \n", multiplicando);

        matrizTabuada[multiplicando] = (short unsigned int *) malloc(QUANTIDADE_OPERACOES_TABUADA * sizeof(short unsigned int));
        if(matrizTabuada[multiplicando] == NULL) {
            printf("\nError na alocação de memória!\n*Encerrando programa*\n");
            exit(0);
        }
        for(multiplicador = INICIO_OPERACOES_TABUADA; multiplicador <= QUANTIDADE_OPERACOES_TABUADA; multiplicador++) {
            produto = multiplicando * multiplicador;
            printf("\t\t %d X %d = %d\n", multiplicando, multiplicador, produto);

            matrizTabuada[multiplicando][multiplicador] = produto;
        }
    }
    return matrizTabuada;
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que calcula a media aritmetica de uma matriz com 10 strings e 10 caracteres
 */
void programaMediaAritmetica() {
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
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que calcula a diferenca entre linhas pares e colunas impares de uma matriz
 */
void programaDiferencasEntreColunas() {
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
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que imprime comecando do 100 e terminando no 0
 */
void programaDe100Ate0() {
    printf("Seja bem vindo ao Programa %d - %s!\n", DE_100_A_1, titulosProgramas[DE_100_A_1]);

    int i;
    for(i = 100; i > 0; i--) {
        printf("%d\n", i);
    }
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief  Funcao que recebe a entrada de caracteres para a funcao principal
 */
void entradaProgramaSubstituirCaracteres() {
    printf("Seja bem vindo ao Programa %d - %s!\n", SUBSTITUIR_CARACTERES, titulosProgramas[SUBSTITUIR_CARACTERES]);
    printf("O programa realiza a substituição dos caracteres 'a' por 'b'\n");

    const int TAMANHO_PALAVRA = 100;

    printf("Digite uma palavra: ");
    char *string = malloc(TAMANHO_PALAVRA * sizeof(char));
    scanf(" %s", string);

    programaSubstituirCaracteres(&string);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que realiza o processamento de uma string,
 *          substituindo os caracteres a por b e contando o numero de carcteres substituidos
 * @param   string para processamento
 */
void programaSubstituirCaracteres(char **pString) {

    int contadorCaracter, i;
    for(i = 0, contadorCaracter =0; (*pString)[i]; i++) {
        if((*pString)[i] == 'a') {
           (*pString)[i] = 'b';
            contadorCaracter++;
        }
    }

    printf("\nQuantidade de caracteres 'a' modificados: %d\n", contadorCaracter);
    printf("Palavra após troca dos caracteres 'a': %s\n", *pString);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que imprime a referencia do caractere na tabela ascii
 * @param   caractere
 */
void imprimirReferenciaASCII(char* caractere) {
    printf("\nCaracter %c - Código ASCII %d\n", caractere, caractere);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que recebe o caractere para processamento
 */
void programaTabelaASCII() {
    printf("Seja bem vindo ao Programa %d - %s!\n", TABELA_ASCII, titulosProgramas[TABELA_ASCII]);

    printf("Digite um caracter: ");
    char caractereDigitado;
    scanf(" %c", &caractereDigitado);

    imprimirReferenciaASCII(caractereDigitado);
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que encerra a execucao do programa
 */
void programaEncerrar() {
    int contadorContagemRegressiva = CONTAGEM_REGRESSIVA;
    while(contadorContagemRegressiva) {
        printf("Contagem regressiva: %d\n", contadorContagemRegressiva--);
        int tempoFinal = time(0) + TEMPO_INTERVALO_CONTAGEM;
        while(time(0) < tempoFinal);
    }
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que informa opcao invalida
 */
void programaInvalido() {
    printf("Opção inválida, tente novamente!");
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao para escolher entre os dois hello word
 * @param   semente
 * @return  verdadeiro ou falso
 */
bool imprimirHelloWordPorPonteiro(unsigned int semente) {
    srand(semente);
    return rand() % 2;
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que imprimi hello word
 */
void helloWord() {
    printf("Hello word! --- (impreso por ponteiro, 2º forma)\n");
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que imprime hello word de duas formas aleatorias
 *
 */
void programaHelloWord() {
    if(imprimirHelloWordPorPonteiro(time(NULL))) {
        void (*helloWordPonteiro)() = &helloWord;
        (*helloWordPonteiro)();
    } else {
        printf("Hello word! --- (impresso normalmente, 1º forma)\n");
    }

}
