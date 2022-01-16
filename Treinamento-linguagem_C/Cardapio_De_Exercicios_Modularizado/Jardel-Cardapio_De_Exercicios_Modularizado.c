/**
 * Academia C/BRM - Accenture
 * ProgramaEscolhido: Cardapio de exercicios Modularizado
 * 15/01/2022
 *
 * @file Jardel-Cardapio_De_Exercicios_Modularizado.c
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @brief Arquivo contndo a funcao principal do programa (main)
 */


#include "menu.h"
#include "programas_auxiliares.h"


/**
 * @author Jardel Brandon de Araujo Regis
 * @date 15/01/2022
 * @version 1.0
 * @brief   A funcao main esta responsavel por realizar a captura do item de execucao
 *          desejado pelo usuario e pela respectiva destinacao ao programa escolhido
 *          assim sucessivamente, basicamente utilizando enum e while para isso,
 *          ate que seja informada a opcao de encerramento geral do programa
 * @param   itemCardapio  um inteiro representando o programa escolhido no menu
 * @return                execucao do programa selecionado
 */
int main() {
    system("color 1f"); // Altera cor de fundo e de fonte do terminal
    setlocale(LC_ALL, "Portuguese"); // Configura a codificacao de caracteres

    MenuProgramas programaEscolhido;

    do {
        imprimirCabecalho();

        imprimirMenu();

        char* entradaMenu = receberOpcaoEscolhidaDoMenu();

        programaEscolhido = (MenuProgramas) validarEntrada(entradaMenu);

        switch (programaEscolhido) {
            case SAUDACAO: {
                programaSaudacao();
                break;
            }
            case CALCULADORA: {
                programaCalculadora();
                break;
            }
            case CONVERSOR_DE_TEMPERATURA: {
                programaConversorDeTemperatura();
                break;
            }
            case FATORIAL: {
                programaFatorial();
                break;
            }
            case MEDIA_ARITMETICA: {
                programaMediaAritmetica();
                break;
            }
            case TABUADA: {
                short unsigned int** matrizTabuada = programaTabuada();
                int linha, coluna;
                for (linha = INICIO_OPERACOES_TABUADA; linha <= QUANTIDADE_OPERACOES_TABUADA; linha++) {
                    if(linha == 5) {
                        continue;
                    }
                    printf("Tabuada do %d: \n", linha);
                    for (coluna = INICIO_OPERACOES_TABUADA; coluna <= QUANTIDADE_OPERACOES_TABUADA; coluna++) {
                        printf("\t\t %d X %d = %d\n", linha, coluna, matrizTabuada[linha][coluna]);
                                            }
                    free(matrizTabuada[linha]);
                }
                free(matrizTabuada);
                break;
            }
            case DIFERENCAS_ENTRE_COLUNAS: {
                programaDiferencasEntreColunas();
                break;
            }
            case DE_100_A_1: {
                programaDe100Ate0(0);
                break;
            }
            case SUBSTITUIR_CARACTERES: {
                entradaProgramaSubstituirCaracteres();
                break;
            }
            case TABELA_ASCII: {
                programaTabelaASCII();
                break;
            }
            case ENCERRAR_PROGRAMA: {
                programaEncerrar();
                break;
            }
            case HELLO_WORD:
                programaHelloWord();
                break;
            default: {
                programaInvalido();
                break;
            }
        }

        imprimirFim();
        system("cls");

    } while(programaEscolhido != ENCERRAR_PROGRAMA);

    return 0;
}
