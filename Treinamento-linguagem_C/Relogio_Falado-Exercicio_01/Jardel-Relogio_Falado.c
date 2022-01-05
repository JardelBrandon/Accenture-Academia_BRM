#include <stdio.h>
#include <stdlib.h>


/**
* Academia C/BRM - Accenture
* Programa: Relogio Falado
* 03/01/2022
*
* @author Jardel Brandon de Araujo Regis
* @version 1.0
* @param   horario  um inteiro representando a hora desejada
* @return           uma mensagem de saudação de acordo com a hora fornecida
*/
int main() {
    int horario = 0;

    printf("Digite a hora: ");
    scanf("%d", &horario);

    if(horario >= 0 && horario < 12) {
        printf("Bom dia!\n");
    } else if(horario >= 12 && horario < 18) {
        printf("Boa tarde!\n");
    } else if(horario >=18 && horario <= 23) {
        printf("Boa noite!\n");
    } else {
        printf("Horário inválido!\n");
    }

    return 0;
}
