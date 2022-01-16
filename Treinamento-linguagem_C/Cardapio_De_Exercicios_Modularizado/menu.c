/**
 * @file menu.c
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @brief Arquivo contndo as implementacoes das definicoes do menu.h
 */

#include "menu.h"

/**
 * @var titulosProgramas
 * @brief Variavel responsavel por armazenar um pequeno titulo descritivos dos programas
 *        que sao apresentados ao usuarios no cardapio de escolhas
 */
char titulosProgramas[][50] = {
        "",
        "Sauda��o",
        "Calculadora",
        "Conversor de temperatura",
        "Fatorial",
        "M�dia Aritim�tica",
        "Tabuada",
        "Diferen�as das m�dias da matriz",
        "Do 1 at� o 100 na ordem inversa",
        "Substituir caracteres",
        "Correspond�ncia na tabela ASCCII",
        "Hello Word"
};

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que realiza a impressao do cabecalho de informacoes de dados gerais
 *          Nome | E-mail | Titulo do programa | Data atual | Data de Criacao | versao
 */
void imprimirCabecalho() {
    printf("******************************************************************************\n");
    printf("********** Jardel Brandon de Araujo Regis | jardelbrandon@gmail.com **********\n");
    printf("**********         Card�pio de exerc�cios | %s             **********\n", __DATE__);
    printf("****************************************************************15/01/2022-1.0\n");
    printf("______________________________________________________________________________\n");
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao qeu realiza a impressao dos itens do menu com seu respectivo valor para selecao
 */
void imprimirMenu() {
    printf("______________________________________________________________________________\n");
    printf("\nCard�pio de programas:\n");
    int referencia = 0;
    for(referencia = SAUDACAO; referencia <= HELLO_WORD; referencia++) {
        printf("\t\t\t %d - %s\n", referencia, titulosProgramas[referencia]);
    }
    printf("\t\t\t exit - Encerrar a execu��o do programa\n");
    printf("______________________________________________________________________________\n");
}

/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   Funcao que realiza a impressao da mensagem de finalizaca do sub-programa selecionado
 */
void imprimirFim() {
    printf("\nFim!\n");
    printf("______________________________________________________________________________\n");
    printf("\nPressione qualquer tecla para continuar. . .\n");
    getch();
}
