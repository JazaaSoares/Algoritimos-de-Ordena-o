#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vet[], int n);

void bubbleSort(int vet[], int n){ n^2
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





int main()
{
     int arr[] = {1,2,3,4,5,6,7};
    int n = 7;

    printf("Array original: \n");
    printVet(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    printVet(arr, n);

    return 0;
}
