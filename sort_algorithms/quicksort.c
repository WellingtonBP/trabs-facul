#include <stdlib.h>
#include <stdio.h>

int partition(int *arr, int start, int end){
   int pivot = arr[end], j = start, i = 0, aux = 0;

   for(i = start; i < end; i++){
      if(arr[i] <= pivot){
         aux = arr[i];
         arr[i] = arr[j];
         arr[j] = aux;
         j++;
      }
   }

   arr[end] = arr[j];
   arr[j] = pivot;

   return j;
}

void quickSort(int *arr, int start, int end){
   int p = 0;
   if(start < end){
      p = partition(arr, start, end);
      quickSort(arr, start, p-1);
      quickSort(arr, p+1, end);
   }
}

void main(){
   int arr[10] = {7,2,334,61,23,54,25,6,0,1}, i = 0;
   quickSort(arr, 0, 9);
   for(i = 0; i<10;i++) printf("%i ", arr[i]);
}
