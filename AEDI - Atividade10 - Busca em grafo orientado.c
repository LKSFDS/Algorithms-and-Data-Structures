#include <stdio.h>
#include <stdlib.h>

//Atividade 10 com grafo orientado (vertice inicial e vertice terminal indicados)

typedef struct{
    int valor;
    tipoItem *prox;
}tipoItem;

typedef struct{
    tipoItem *inicio, *fim;
}tipoFila;

typedef struct{
    int vert_dest;
    int custo;
    tipoListaAdj *prox;
}tipoListaAdj;

typedef struct{
    int maxVert;
    int maxAresta;
    tipoListaAdj **adj;
}tipoGrafo;

//construir uma função do tipo inicializaFila

//construir uma função do tipo inserirFila

//construir uma função do tipo removerFila

void inicializaFila(tipoFila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

void iniciaGrafo(tipoGrafo *G,int nvert){

  int i;

  G = (tipoGrafo *)malloc(sizeof(tipoGrafo));
  G->adj = (adjlist **)malloc(nvert * sizeof(adjlist*));

  for(i = 0; i < nvert; i++){
        G->adj[i] = NULL;
    }

  G->maxVert = nvert;

}

void adicionaArestaGrafo(tipoGrafo* G, int v, int w){

    tipoListaAdj *listaAdj;
    listaAdj = (tipoListaAdj*)malloc(sizeof(struct tipoListaAdj));
    listaAdj->vert_dest = w;
    listaAdj->custo = 1;

    if(G->adj[v] == NULL){
        listaAdj->prox = G->adj[v];
        G->adj[v] = listaAdj;
    }else{
        tipoListaAdj *N;
        N = G->adj[v];
        if (listaAdj->vert_dest < N->vert_dest){
            listaAdj->prox = G->adj[v];
            G->adj[v] = listaAdj;
        }else{
            while (N->prox){
                if(listaAdj->vert_dest < N->prox->vert_dest){
                    break;
                }
            N = N->prox;
            }
      listaAdj->prox = N->prox;
      N->prox = listaAdj;
        }
    }
}

void DFSUtil(tipoGrafo* G, int v, int *visitado){

    visitado[v] = 1;
    printf("%d", v);

    tipoListaAdj *L = G->adj[v];

    while(L){
        if (!visitado[L->vert_dest]){
            DFSUtil(G, L->vert_dest, visitado);
        }

        L = L->next;

    }

}

void DFS(tipoGrafo* G, int v){

    int *visitado = (int*)malloc(G->maxVert*sizeof(int));
    int i;

    for(i = 0; i < G->maxVert; i++){
        visitado[i] = 0;
    }

    DFSUtil(G, v, visitado);
    printf("\n");

}

void BFS(tipoGrafo* G, int v){                    // arrumar a tipagem   // breath-first search (algoritmo de busca em largura)

    int *visitado = (int*)malloc(G->size*sizeof(int));
    int i;

    for(i = 0; i < G­>size; i++){
        visitado[i] = 0;
    }

    tipoFila fila;
    inicializaFila(&fila);
    visitado[v] = 1;
    TipoItemFila item;
    item.valor = v;
    inserirFila(&fila, item);
    TipoItemFila s;
    tipoListaAdj *L;

    while(!filaVazia(&fila)){
        s = removerFila(&fila);
        printf("%d ", s.valor);
        L = G->adj[s.valor];

        while(L){
            if(!visitado[L-­>vert]){
                visitado[L­->vert] = 1;
                item.valor = L->vert;
                inserirFila(&fila, item);
            }

        L = L­->next;

        }

    }

    printf("\n");
}


int main()
{

    int V, N, M, i, vert_ini, vert_fim;

  //printf("Informa o vertice onde a busca devera ser iniciada(0 <= V <= 100):\n");
    scanf("%d", &V);

  //printf("Informe o numero total de vertices contidos no grafo(0 <= N <= 100):\n");
    scanf("%d", &N);

  //printf("Informe o numero de arestas contidas no grafo(1 <= M <= 200):\n");
    scanf("%d", &M);

    tipoGrafo grafo;

    iniciaGrafo(&grafo, N);

    for(i = 0; i < N; i++){
        //printf("Informe o vertice inicial e o vertice final:\n");
        scanf("%d %d", &vert_ini, &vert_fim);
        adicionaArestaGrafo(&grafo, vert_ini, vert_fim);
        i++;
    }


    // criar um for para adicionar as arestas chamando a função adicionaArestaGrafo
    // chamar ambas as funções de busca e verificar se a saida está de acordo





    return 0;
}
