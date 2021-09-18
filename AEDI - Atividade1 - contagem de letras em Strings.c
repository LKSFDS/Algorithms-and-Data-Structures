#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Write a program that will count the number of characters and how many times each one of them will repeat.

int main()
{

    char string[256], vet[26];
    int lenght, j, i, cont;

    //printf("Programa para contagem de letras (e quantas vezes elas se repetem) com output em ordem alfabetica! \n");

    //printf("Digite o texto (maximo de 256 caracteres):\n");
    fgets(string, 256, stdin);

    lenght = strlen(string);

    for(i=0; i<lenght; i++){
        string[i] = toupper(string[i]);
        }

    for(j=65; j<=90; j++){
        cont = 0;
        for(i=0; i<lenght; i++){
            if(string[i] == j){
                cont++;
            }
        }
        if(cont != 0){
            printf("%c %d \n", j, cont);
        }
    }

    return 0;
}
