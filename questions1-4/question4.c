#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end){
   int pivot = arr[start], j = start+1, i = 0, aux = 0;

   for(i = start+1; i < end; i++){
      if(arr[i] <= pivot){
         aux = arr[i];
         arr[i] = arr[j];
         arr[j] = aux;
         j++;
      }
   }
   
   if(j > 1){
      aux = arr[start];
      arr[start] = arr[j-1];
      arr[j-1] = aux;
   }

   return j-1;
}

void quickSort(int *arr, int start, int end){
   int p = 0, i = 0;

   if(start < end){
      p = partition(arr, start, end);
      quickSort(arr, start, p);
      quickSort(arr, p+1, end);
   }
}

void main(){
   int *arr, *partialArrays[2], partialSizes[2], i = 0, j = 0, start = 0, size = 0, middleItem = 0;

   printf("Digite a quantidade de items: ");
   scanf("%i", &size);

   arr = (int *) malloc(size * sizeof(int));

   for(i = 0; i < size; i++){
      printf("Digite o item %i: ",i+1);
      scanf("%i", &arr[i]);
   }

   middleItem = partition(arr, 0, size);
   partialSizes[0] = middleItem;
   partialSizes[1] = size - middleItem-1;

   for(i = 0; i < 2; i++){
      start = i == 0 ? 0 : middleItem+1;
      partialArrays[i] = (int *) malloc(partialSizes[i] * sizeof(int));
      for(j = 0; j < partialSizes[i]; j++) partialArrays[i][j] = arr[start+j];
      quickSort(partialArrays[i], 0, partialSizes[i]);
   }

   printf("\nResult: \n ");
   for(i = 0; i < size; i++) printf("%i ", arr[i]);
   for(i = 0; i < 2; i++){
      printf("\nParte %i ordenada: \n ", i+1);
      for(j = 0; j < partialSizes[i]; j++) printf("%i ", partialArrays[i][j]);
   }
}