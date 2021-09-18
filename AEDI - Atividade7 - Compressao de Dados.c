#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int qntd;
    char caracter;
    struct item *ant, *prox;
}TipoItem;

typedef struct{
    TipoItem *inicio, *fim;
}TipoListaDinamicaDE;

void inicLista(TipoListaDinamicaDE *lista1){

    lista1->inicio = NULL;
    lista1->fim = NULL;

}

void insereElemento(TipoListaDinamicaDE *lista1, char caracter1){

    TipoItem *itemAux = malloc(sizeof(TipoItem));

    itemAux->caracter = caracter1;
    itemAux->qntd = 1;

    if(lista1->inicio == NULL){
        itemAux->ant = NULL;
        itemAux->prox = NULL;
        lista1->inicio = itemAux;
        lista1->fim = itemAux;
    }else{
        itemAux->ant = lista1->fim;
        itemAux->prox = NULL;
        lista1->fim->prox = itemAux;
        lista1->fim = itemAux;
    }

}

void imprimeElementos(TipoListaDinamicaDE *lista1){

    TipoItem *itemAux = lista1->inicio;
    int length;
    length = 0;

    while(itemAux != NULL){
        if(itemAux->qntd > 999){
            length += 5;
        }else if(itemAux->qntd > 99){
            length += 4;
        }else if(itemAux->qntd > 9){
            length +=3;
        }else{
            length +=2;
        }
        itemAux = itemAux->prox;
    }

    printf("%d\n", length);

    itemAux = lista1->inicio;

    while(itemAux != NULL){
        printf("%d%c", itemAux->qntd, itemAux->caracter);
        itemAux = itemAux->prox;
        }

    printf("\n");

}

TipoItem *removeElemento(TipoListaDinamicaDE *lista1, TipoItem *itemAux){

    TipoItem *itemAux2;

    if(itemAux == lista1->inicio){
        lista1->inicio = itemAux->prox;
        lista1->inicio->ant = NULL;
        free(itemAux);
        return lista1->inicio;
    }else if(itemAux == lista1->fim){
        lista1->fim = itemAux->ant;
        lista1->fim->prox = NULL;
        free(itemAux);
        return lista1->fim;
    }else{
        itemAux2 = itemAux->prox;
        itemAux->ant->prox = itemAux->prox;
        itemAux->prox->ant = itemAux->ant;
        free(itemAux);
        return itemAux2;
    }

}

void compactarElementos(TipoListaDinamicaDE *lista1){

    TipoItem *itemAux = lista1->inicio;

    while(itemAux != NULL){
        if(itemAux->qntd == 1){
            if(itemAux == lista1->inicio){
                if(itemAux->prox->qntd > 1){
                    itemAux->prox->qntd++;
                    itemAux = removeElemento(lista1, itemAux);
                }else {
                    itemAux = itemAux->prox;
                    }
            }else if(itemAux == lista1->fim){
                if(itemAux->ant->qntd >1){
                    itemAux->ant->qntd++;
                    itemAux = removeElemento(lista1, itemAux);
                }else{
                    itemAux = itemAux->prox;
                    }
            }else{
                if(itemAux->ant->qntd > 1){
                    if(itemAux->prox->qntd > 1){
                        if(itemAux->ant->qntd < itemAux->prox->qntd){
                            itemAux->prox->qntd++;
                            itemAux = removeElemento(lista1, itemAux);
                        }else{
                            itemAux->ant->qntd++;
                            itemAux = removeElemento(lista1, itemAux);
                        }
                    }else{
                        itemAux = itemAux->prox;
                    }
                }else{
                    itemAux = itemAux->prox;
                }
            }

            }else{
                itemAux = itemAux->prox;
            }
        }
}

int main(){

    int contador;
    char string[1023];
    TipoListaDinamicaDE Lista;

    inicLista(&Lista);

    /*printf("Digite a string desejada:\n");*/
    scanf("%s", string);

    for(contador = 0; string[contador] != '\0'; contador++){
        if(string[contador] != string[contador - 1]){
            insereElemento(&Lista, string[contador]);
        }else{
            Lista.fim->qntd++;
        }
    }

    imprimeElementos(&Lista);

    compactarElementos(&Lista);

    imprimeElementos(&Lista);


    return 0;
}
