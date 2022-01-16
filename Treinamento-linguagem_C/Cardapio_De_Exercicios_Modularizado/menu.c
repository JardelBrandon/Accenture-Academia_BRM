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
    printf("**********         Cardápio de exercícios | %s             **********\n", __DATE__);
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
    printf("\nCardápio de programas:\n");
    int referencia = 0;
    for(referencia = SAUDACAO; referencia <= HELLO_WORD; referencia++) {
        printf("\t\t\t %d - %s\n", referencia, titulosProgramas[referencia]);
    }
    printf("\t\t\t exit - Encerrar a execução do programa\n");
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
