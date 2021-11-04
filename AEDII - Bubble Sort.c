#include <stdio.h>
#include <stdlib.h>

/*AED2 2021 (2s) - EXERCICIO 3.1 - JOGO DAS BOLHAS*/
/* Lucas Freire de Siqueira    RA: 133684    03/11/2021 */

int jogoBolhas(int *P, int N, int player){

    int chamaRec, aux, i;
    int cont = 0;

    for(i = 0; i < N; i++){
        if(P[i] > P[i+1] && P[i+1] != NULL){
            aux = P[i+1];
            P[i+1] = P[i];
            P[i] = aux;
            cont++;
        }

        if(cont == 1){
            if(player == 0){
                player++;
            }else if(player == 1){
                player--;
            }
            chamaRec = jogoBolhas(P, N, player);
            player = chamaRec;
            cont = 0;
        }
    }

    return player;
}

int main()
{
    int i, vencedor, N;

    scanf("%d",&N);

    int P[N];

    for(i = 0; i < N; i++){
        scanf("%d", &P[i]);
    }

    int playerIni = 0;

    vencedor = jogoBolhas(&P, N, playerIni);

    for(i = 0; i < N; i++){
        printf("%d ", P[i]);
    }
    printf("\n");
    if(vencedor == 0){
        printf("Carlos");
    }else{
        printf("Marcelo");
    }

    return;
}
