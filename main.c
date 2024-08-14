#include <stdio.h>
#include <stdlib.h>

//fun��o 'merge' � respons�vel por mesclar dois subvetores ordenados em ordem crescente
void merge(int arr[], int inicio, int meio, int fim) {
    //ela recebe o vetor 'arr', o �ndice de in�cio, �ndice do meio e o �ndice do fim desses subvetores que ser�o mesclados
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

//criando subvetores tempor�rios
/*          Estou criando subvetores tempor�rios chamados 'esquerda' e 'direita' para armazenar os elementos dos subvetores.
            Esses elementos dos subvetores s�o copiados para os subvetores tempor�rios e mesclados em ordem crescente no vetor original 'arr',
            comparando os elementos dos subvetores tempor�rios e colocando o menor elemento no vetor 'arr'.    */

    int *esquerda = (int *)malloc(tamanhoEsquerda * sizeof(int));
    int *direita = (int *)malloc(tamanhoDireita * sizeof(int));

//preenchendo os subvetores tempor�rios
    for (int i = 0; i < tamanhoEsquerda; i++)
        esquerda[i] = arr[inicio + i];
    for (int j = 0; j < tamanhoDireita; j++)
        direita[j] = arr[meio + 1 + j];

//mesclando os subvetores tempor�rios em ordem crescente
    int i = 0, j = 0, k = inicio;
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            arr[k] = esquerda[i];
            i++;
        } else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }

//copiando os elementos restantes do subvetor esquerdo, se houver
    while (i < tamanhoEsquerda) {
        arr[k] = esquerda[i];
        i++;
        k++;
    }

//copiando os elementos restantes do subvetor direito, se houver
    while (j < tamanhoDireita) {
        arr[k] = direita[j];
        j++;
        k++;
    }

//ao final, libero a mem�ria alocada para os subvetores tempor�rios
    free(esquerda);
    free(direita);
}

//fun��o 'mergeSort' � a principal do algoritmo MergeSort
void mergeSort(int arr[], int inicio, int fim) {
    //recebe o vetor 'arr', o �ndice de in�cio e o �ndice de fim dos elementos a serem ordenados.

    if (inicio < fim) {
/*          Ela verifica se o �ndice de in�cio � menor que o �ndice de fim. Caso seja, o vetor � dividido em duas partes, calculando o �ndice do meio.
            A fun��o faz chamadas recursivas para ordenar a primeira metade do vetor (mergeSort(arr, inicio, meio)) e a segunda metade do vetor (mergeSort(arr, meio + 1, fim)).
            Ap�s as chamadas recursivas, a fun��o chama a fun��o merge para mesclar os subvetores ordenados. */
        int meio = inicio + (fim - inicio) / 2;

//chamada recursiva para ordenar os subvetores
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

//mesclando os subvetores ordenados
        merge(arr, inicio, meio, fim);
    }
}

//fun��o 'main'
int main() {
    int tamanho = 200000;
//aqui declaro o tamanho do vetor conforme solicitado na descri��o do trabalho: 50mil, 100mil, 150mil e 200mil n�meros inteiros
    int arr[tamanho];

//aqui preencho o vetor com n�meros inteiros aleat�rios utilizando o 'rand' para n�o ter que digitar 50, 100, 150 e 250 mil n�meros
    for (int i = 0; i < tamanho; i++)
        arr[i] = rand();

//aqui ele mostra na tela o vetor original, desordenado
    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);

//aqui ele ordena o vetor usando o MergeSort
    mergeSort(arr, 0, tamanho - 1);

//aqui ele mostra na tela o vetor ordenado ap�s utilizar o MergeSort
    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);

    return 0;
}
