#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char strx[80], stry[80], strz[160], caracter[1];
    int x, newx, y, newy, contz, contc, i, j;

    //printf("Informe o tamanho de cada string e o caracter a ser contado:\n");
    scanf("%d%d%s", &x, &y, caracter);

    //printf("%d %d %s", x, y, caracter);

    //printf("\nInforme as duas strings, separando-as por um espaco:\n");
    scanf("%s%s", strx, stry);

    //printf("%s%s", strx, stry);

    for(i = 0; i < 80 && strx[i] != '\0' ; i++){
        newx = i;
    }

    for(i = 0; i < 80 && stry[i] != '\0' ; i++){
        newy = i;
    }

    //printf("%d\n", newx);
    //printf("%d\n", newy);


    contz = (newx + 1) + (newy + 1);  //é preciso adicionar mais 1 em cada variavel pois elas pegam o valor da ultima posiçao antes do caracter \0

    //printf("%d", contz);

    for(i = 0; i <= newx; i++){
        strz[i] = strx[newx - i];
    }

    j = 0;

    for(i = newx + 1; i <= newy + newx + 1; i++){
        strz[i] = stry[newy - j];
        j++;
    }

    contc = 0;

    for(i = 0; i < 160 && strz[i] != '\0'; i++){
        if(strz[i] == caracter[0]){
            contc++;
        }
    }

    printf("%s\n%d\n%d\n", strz, contz, contc);  //string z
    //printf("%d\n", contz); //tamanho real da string z
    //printf("%d\n", contc); // quantidade de vezes que o caracter c aparece na string z

}
