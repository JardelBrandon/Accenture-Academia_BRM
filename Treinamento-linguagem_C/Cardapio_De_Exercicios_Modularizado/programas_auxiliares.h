/**
 * @file programas_auxiliares.h
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @brief Arquivo contndo cabecalho e definicoes das funcoes auxiliares
 *        que sao utilizadas pelos subprogramas executados
 */

#ifndef PROGRAMAS_AUXILIARES_H_INCLUDED
#define PROGRAMAS_AUXILIARES_H_INCLUDED

#include "menu.h"
#include <locale.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define QUADRADO 2
#define METADE 2
#define TAMANHO_MAXIMO_ENTRADA 5
#define TAMANHO_MAXIMO_ENTRADA_NOME 100
#define CONTAGEM_REGRESSIVA 10
#define TEMPO_INTERVALO_CONTAGEM 1
#define STRING_ENCERRAR_PROGRAMA "exit"
#define INICIO_OPERACOES_TABUADA 1
#define QUANTIDADE_OPERACOES_TABUADA 10

char* receberOpcaoEscolhidaDoMenu();

int validarEntrada(char *entrada);

void programaSaudacao();

void programaCalculadora();

void programaConversorDeTemperatura();

void programaFatorial();

short unsigned int** programaTabuada();

void programaMediaAritmetica();

void programaDiferencasEntreColunas();

void programaDe100Ate0();

void entradaProgramaSubstituirCaracteres();

void programaSubstituirCaracteres(char** pString);

void programaTabelaASCII();

void programaEncerrar();

void programaInvalido();

bool imprimirHelloWordPorPonteiro(unsigned int semente);

void programaHelloWord();

void helloWord();

#endif // PROGRAMAS_AUXILIARES_H_INCLUDED
