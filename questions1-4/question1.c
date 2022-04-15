#include <stdio.h>
#include <stdlib.h>

void sortFirstItem(int *arr, int size){
   int first = arr[0], j = 1, i = 1, aux = 0;

   for(i = 1; i < size; i++){
      if(arr[i] <= first){
         aux = arr[i];
         arr[i] = arr[j];
         arr[j++] = aux;
      }
   }

   if(j > 1){
      aux = arr[j-1];
      arr[j-1] = arr[0];
      arr[0] = aux;
   }
}

void main(){
   int *arr, i = 0, size = 0;

   printf("Digite a quantidade de items: ");
   scanf("%i", &size);

   arr = malloc(size * sizeof(int));

   for(i = 0; i < size; i++){
      printf("Digite o item %i: ",i+1);
      scanf("%i", &arr[i]);
   }

   sortFirstItem(arr, size);

   printf("\nResult: \n");
   for(i = 0; i < size; i++) printf("%i ", arr[i]);
}