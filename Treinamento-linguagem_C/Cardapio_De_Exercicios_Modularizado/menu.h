/**
 * @file menu.h
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @brief Arquivo contndo cabecalho e definicoes do menu apresentado na tela
 *        com o intuito de melhorar a experiencia do usuario
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void imprimirCabecalho();
void imprimirMenu();
void imprimirFim();


/**
 * @enum MenuProgramas
 * @brief Enumercao das opcoes de programas para execucao
 */
typedef enum {
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
    HELLO_WORD,
    ENCERRAR_PROGRAMA = -1,
    INVALIDO = -2
} MenuProgramas;

extern char titulosProgramas[][50];

#endif // MENU_H_INCLUDED
