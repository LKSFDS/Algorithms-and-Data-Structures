#include <stdlib.h>
#include <stdio.h>

/* Lucas Freire de Siqueira   RA: 133684  AED2 2021 2ºSemestre
   QuickSort Algorithm*/



int partitionFunc(int *v, int start, int last){

    int aux, j;
    int x = v[last];
    int i = start-1;

    for(j = start; j < last; j++){
        if(v[j] <= x){
            i = i + 1;
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
        }
    }

    aux = v[last];
    v[last] = v[i+1];
    v[i+1] = aux;

    return i+1;

}

void quickSort(int *v, int start, int last, int pos){

    int pivot;

    if(start < last){
        pivot = partitionFunc(v, start, last);
        if(pivot == pos){
            return;
        }else if(pos < pivot){
            quickSort(v, start, pivot-1, pos);
        }else{
            quickSort(v, pivot+1, last, pos);
        }
    }
}


int main(){

    int K, N, i, element;

    scanf("%i", &K);
    scanf("%i", &N);

    int v[N];

    for(i = 0; i < N; i++){
        scanf("%i", &v[i]);
    }

    int start = 0;
    int last = N-1;
    int pos = K-1;

    quickSort(v, start, last, pos);

    printf("%io menor elemento eh o %i", K, v[pos]);
    printf("\n");

    for(i = 0; i < N; i++){
        printf("%d ", v[i]);
    }


    return 0;
}
