#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int coef;
    int exp;
    struct TipoMonomio *ant;
    struct TipoMonomio *prox;
}TipoMonomio;

typedef struct{
   TipoMonomio *fim;
   int tamanho;
}TipoPolinomio;

void iniciaLista(TipoPolinomio *poli){

    poli->fim = NULL;
    poli->tamanho = 0;

}

void insereMonomio(TipoPolinomio *poli, int C, int E){

    TipoMonomio *novoMonomio;
    novoMonomio = malloc(sizeof(TipoMonomio));
    novoMonomio->coef = C;
    novoMonomio->exp = E;
    novoMonomio->ant = NULL;
    novoMonomio->prox = NULL;

    if(poli->fim == NULL){
        poli->fim = novoMonomio;
    }else if(poli->fim != NULL){
        if(poli->fim->exp < novoMonomio->exp){
            poli->fim->prox = novoMonomio;
            novoMonomio->ant = poli->fim;
            poli->fim = novoMonomio;
        }else if(poli->fim->exp == novoMonomio->exp){
            poli->fim->coef = (poli->fim->coef) + (novoMonomio->coef);
            free(novoMonomio);
            if(poli->fim->coef == 0){
                if(poli->fim->ant!=NULL){
                    TipoMonomio *aux;
                    aux = poli->fim;
                    poli->fim = aux->ant;
                    poli->fim->prox = aux->prox;
                    aux->ant = NULL;
                    free(aux);
                }else{
                    free(poli->fim);
                    poli->fim = NULL;
                }
            }
        }else if(novoMonomio->exp < poli->fim->exp){
            TipoMonomio *aux;
            aux = poli->fim;
            while(novoMonomio->exp < aux->exp && aux->ant != NULL){
                aux = aux->ant;
            }
            if(aux->ant == NULL && novoMonomio->exp < aux->exp){
                aux->ant = novoMonomio;
                novoMonomio->prox = aux;
            }else if(aux->exp == novoMonomio->exp){
                aux->coef = (aux->coef) + (novoMonomio->coef);
                free(novoMonomio);
                if(aux->coef == 0){
                    if(aux->ant == NULL){
                        aux = aux->prox;
                        free(aux->ant);
                        aux->ant = NULL;
                    }else{
                    TipoMonomio *aux2;
                    aux2 = aux->ant;
                    aux2->prox = aux->prox;
                    aux2 = aux->prox;
                    aux2->ant = aux->ant;
                    aux->prox = NULL;
                    aux->ant = NULL;
                    free(aux);
                    free(novoMonomio);
                    }
                }
            }
            }
        }

}

void imprimePolinomio(TipoPolinomio *poli){

    TipoMonomio *aux;


    while(poli->fim != NULL){

        if(poli->fim->coef > 0){
            printf("+%dx^%d ", poli->fim->coef, poli->fim->exp);
            poli->tamanho = poli->tamanho + 1;
        }else{
            printf("%dx^%d ", poli->fim->coef, poli->fim->exp);
            poli->tamanho = poli->tamanho + 1;
        }


        aux = poli->fim;
        poli->fim = aux->ant;
        poli->fim->prox = NULL;
        free(aux);
        if(poli->fim->ant == NULL){
            free(poli->fim);
            poli->fim = NULL;
        }
    }

    printf("\n");
    printf("%d\n", poli->tamanho);

}

int main(){

    int N, C, E, i;
    TipoPolinomio Polinomio;

    iniciaLista(&Polinomio);

    //printf("Insira quantidade de monomios a que formarao o polinomio (1 <= N <= 1023):\n");
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        //printf("\nInforme o valor do coeficiente (-10000 <= C <= 10000) e do expoente (0 <= E <= 1023):\n");
        scanf("%d %d", &C, &E);
        insereMonomio(&Polinomio, C, E);
    }

    imprimePolinomio(&Polinomio);


    return 0;
}
