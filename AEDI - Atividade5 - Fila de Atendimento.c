#include<stdio.h>
#include<stdlib.h>

typedef struct TipoCliente{
    int cliente;
    int tempo;
    struct TipoCliente* proximo;
}TipoCliente;

typedef struct TipoFila{
    TipoCliente* inicio;
    TipoCliente* fim;
}TipoFila;

void inicializaFila(TipoFila* filaD){
    filaD->inicio = NULL;
    filaD->fim = NULL;
    }

void inseriCliente(TipoFila* filaCaixa, int idCliente, int tempoAtendimento){
    TipoCliente* novoCliente = malloc(sizeof(TipoCliente));
    novoCliente->cliente = idCliente;
    novoCliente->tempo = tempoAtendimento;
    novoCliente->proximo = NULL;

    if(filaCaixa->inicio == NULL){
       filaCaixa->inicio = novoCliente;
       filaCaixa->fim = novoCliente;
       }else{
        filaCaixa->fim->proximo = novoCliente;
        filaCaixa->fim = novoCliente;
        }
    }

int VerificaTempo(TipoFila* filaCaixa){
    int tempoSoma = 0;
    TipoCliente* Aux;

    for (Aux = filaCaixa->inicio; Aux != NULL; Aux = Aux->proximo){
        tempoSoma += Aux->tempo;
        }
    return tempoSoma;
}

int main() {
    int quantidadeCliente, quantidadeCaixa, tempoAtendimento, id, i, soma, posicao;

    TipoFila filaClientes;
    TipoFila filaCaixas[25];
    TipoCliente* Aux;

    //printf("Insira a quantidade de clientes e a quantidade de caixas:\n");
    scanf("%d %d", &quantidadeCliente, &quantidadeCaixa);

    inicializaFila(&filaClientes);

    for(id = 1; id <= quantidadeCliente; id++){
        //printf("Insira o tempo de atendimento de cada cliente:\n");
        scanf("%d", &tempoAtendimento);
        inseriCliente(&filaClientes, id, tempoAtendimento);
        }
    for (i = 0; i < quantidadeCaixa; i++){
        inicializaFila(&filaCaixas[i]);
        }

    Aux = filaClientes.inicio;

    for(i=0; i<quantidadeCaixa && Aux != NULL; i++){
        inseriCliente(&filaCaixas[i], Aux->cliente, Aux->tempo);
        Aux = Aux->proximo;
        }

    while(Aux != NULL){
        soma = VerificaTempo(&filaCaixas[0]) + Aux->tempo;
        posicao = 0;

        for(i=0; i<quantidadeCaixa; i++){
            if (soma > (VerificaTempo(&filaCaixas[i]) + Aux->tempo)){
                soma = VerificaTempo(&filaCaixas[i]) + Aux->tempo;
                posicao = i;
                }
            }
        inseriCliente(&filaCaixas[posicao], Aux->cliente, Aux->tempo);
        Aux = Aux->proximo;
        }

    for(i=0; i<quantidadeCaixa; i++){
        printf("%d: ", i+1);
        for ( Aux = filaCaixas[i].inicio; Aux != NULL; Aux = Aux->proximo){
            printf("%d ", Aux->cliente, Aux->tempo);
            }
        printf("\n");
        }

    return 0;

}
