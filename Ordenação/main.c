#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vet[], int n);
void mergeSort(int *vet, int inicio, int fim);
void merge(int *vet, int iniciio, int meio, int fim);


void bubbleSort(int *vet, int n){ //n^2
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1; j++){
            if(vet[j]>vet[j+1]){
              //  printf("Antes : %d , %d \n ", vet[j], vet[j+1]);
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
               // printf("Depois: %d , %d \n i: %d j: %d n: %d ", vet[j], vet[j+1], i,j,n);
            }
           // printf("Eita i :%d , %d \n\n ", vet[j], vet[j+1]);
        }
    }
}

void printVet(int vet[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void mergeSort(int *vet, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2); //divide o vetor em 2
        mergeSort(vet,inicio,meio); // chama o mergSort pra primeira metade
        mergeSort(vet, meio+1,fim); //chama o mergSort pra segunda metade + 1
        merge(vet, inicio, meio, fim); //combina as 2 metades de forma ordenada
    }
}

void merge(int *vet, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i , j , k;
    int fim1 = 0;
    int fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int*) malloc(tamanho*sizeof(int));

    if(temp!= NULL){
        for (i = 0; i < tamanho; i++) {
            if (p1 <= meio && p2 <= fim) {
                // Combina os dois sub-vetores ordenados
                if (vet[p1] < vet[p2]) {
                    temp[i] = vet[p1++];
                } else {
                    temp[i] = vet[p2++];
                }
            } else if (p1 > meio) {
                // Se o primeiro sub-vetor acabou, copia o restante do segundo
                temp[i] = vet[p2++];
            } else {
                // Se o segundo sub-vetor acabou, copia o restante do primeiro
                temp[i] = vet[p1++];
            }
        }

        for(j=0, k= inicio; j<tamanho; j++ , k++){ //passa do auxiliar pro original
            vet[k] =  temp[j];
        }
    }
    free(temp);
}

int main()
{
    int vet[] = {1,2,45,12,69,35,27};
    int n = 7;

    printf("Array original: \n");
    printVet(vet, n);

    bubbleSort(vet, n);

    printf("Array ordenado: \n");
    printVet(vet, n);

    int vet2[] = {56,69,323,45,12364,98521,100000,3,-5};
    n = 9;
    int inicio = 0;
    int fim = n-1;

    printVet(vet2, n);

    mergeSort(vet2, inicio, fim);

    printVet(vet2, n);

    return 0;
}
