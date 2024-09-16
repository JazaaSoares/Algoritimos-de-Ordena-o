#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void geradorVetorAleatorio(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Gera números aleatórios entre 0 e size
    }
}

void geradorVetorOrdenado(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i; // Gera números ordenados
    }
}

void geradorVetorOrdenadoReverso(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = size - i - 1; // Gera números em ordem reversa
    }
}

void calculaTempoExecucao(void (*sortFunction)(int[], int), int arr[], int size, const char *algorithmName) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunction(arr, size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para %s: %f segundos\n", algorithmName, cpu_time_used);
}

void calculaTempoExecucaoMergSort(void (*sortFunction)(int[], int, int), int arr[], int left, int right, const char *algorithmName) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunction(arr, left, right);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para %s: %f segundos\n\n", algorithmName, cpu_time_used);
}

int main() {
    int tamanhos[] = {100, 1000, 10000, 100000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < numTamanhos; i++) {
        int tamanho = tamanhos[i];
        int *vetor = (int *)malloc(tamanho * sizeof(int));
        printf("-----------------------------------------------------\n");

        printf("Tamanho do vetor: %d\n", tamanho);

        // Dados Aleatórios
        geradorVetorAleatorio(vetor, tamanho);
        calculaTempoExecucao(bubbleSort, vetor, tamanho, "Bubble Sort (aleatorio)");
       // calculaTempoExecucao(selectionSort, arr, size, "Selection Sort (aleatorio)");
        //calculaTempoExecucao(insertionSort, arr, size, "Insertion Sort (aleatorio)");
        calculaTempoExecucaoMergSort(mergeSort, vetor, 0, tamanho-1, "Merge Sort (aleatorio)");

        // Dados Ordenados
        geradorVetorOrdenado(vetor, tamanho);
        calculaTempoExecucao(bubbleSort, vetor, tamanho, "Bubble Sort (Ordenado)");
       // calculaTempoExecucao(selectionSort, arr, size, "Selection Sort (Ordenado)");
      //  calculaTempoExecucao(insertionSort, arr, size, "Insertion Sort (Ordenado)");
        calculaTempoExecucaoMergSort(mergeSort, vetor, 0, tamanho-1, "Merge Sort (Ordenado)");

        // Dados Reversamente Ordenados
        geradorVetorOrdenadoReverso(vetor, tamanho);
        calculaTempoExecucao(bubbleSort, vetor, tamanho, "Bubble Sort (Ordenado reverso)");
        //calculaTempoExecucao(selectionSort, arr, size, "Selection Sort (Ordenado reverso)");
       // calculaTempoExecucao(insertionSort, arr, size, "Insertion Sort (Ordenado reverso)");
        calculaTempoExecucaoMergSort(mergeSort, vetor, 0, tamanho-1, "Merge Sort (Ordenado reverso)");
        free(vetor);
    }

    return 0;
}
