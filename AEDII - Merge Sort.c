#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Lucas Freire de Siqueira    RA: 133684    AED2 (2021/2s)*   UNIFESP - SJC/
/*MergeSort Algorithm*/

int cont = 0;


void mergeFunc(int *v, int start, int middle, int last, int K){

    int l, r, i, j;
    l = middle - start + 1;
    r = last - middle;
    int vSize = last - start + 1;

    int left[l];
    int right[r];

    for(i = 0; i < l; i++){
        left[i] = v[start + i];
    }
    for(j = 0; j < r; j++){
        right[j] = v[middle + 1 + j];
    }

    i = 0;
    j = 0;

    while(i < l && j < r){
        if(left[i] < (right[j]*K)){
            i++;
        }else if(left[i] == (right[j]*K)){
            i++;
        }else{
            j++;
            cont = cont + l - i;
        }
    }

    int m = 0;
    int n = 0;
    int p = 0;
    int aux = start;

    for(m = 0; m < vSize; m++){
        if(n < l && p < r){
            if(left[n] < right[p]){
                v[aux] = left[n];
                n++;
            }else if(left[n] == right[p]){
                v[aux] = left[n];
                n++;
            }else{
                v[aux] = right[p];
                p++;
            }
        aux = aux + 1;
        }
    }

    while(n < l){
        v[aux] = left[n];
        aux++;
        n++;
    }
    while(p < r){
        v[aux] = right[p];
        aux++;
        p++;
    }

}

void mergeSort(int *v, int start, int last, int K){

    int middle;
    if(start < last){
        middle = floor((start+last)/2);
        mergeSort(v, start, middle, K);
        mergeSort(v, middle+1, last, K);
        mergeFunc(v, start, middle, last, K);
    }
    return;
}

int main(){

    int K, i, N;

    scanf("%i", &N);

    scanf("%i", &K);

    int v[N];

    for(i = 0; i < N ; i++){
        scanf("%i", &v[i]);
    }

    int start, last;
    start = 0;
    last = N-1;

    mergeSort(v, start, last, K);

    printf("%i", cont);

    return 0;
}
