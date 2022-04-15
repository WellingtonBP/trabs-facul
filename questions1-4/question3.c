#include<stdio.h>
#include<stdlib.h>

void sort(int *arr, int size){
   int i = 0, j = 0, aux;

   for (i = 1; i < size; i++){
      for(j = 0; j < size-i; j++){
         if(arr[j] > arr[j+1]){
            aux = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = aux;
         }
      }
   }
}

int search(int *arr, int start, int end, int value){
   if(start > end) return -1;
   int middle = (start + end) / 2;
   if(arr[middle] == value) return middle;
   if(arr[middle] > value) return search(arr, start, middle-1, value);
   return search(arr, middle+1, end, value);
}

int countOccurrences(int *arr, int pos, int size) {
   int count = 1, i = 1;

   while(pos-i >= 0 && arr[pos-i++] == arr[pos]) count++;
   i = 1;
   while(pos+i < size && arr[pos+i++] == arr[pos]) count++;

   return count;
}

void main(){
   int *arr, size = 0, i = 0, value = 0, pos = 0;

   printf("Digite o tamanho do array: ");
   scanf("%i", &size);

   arr = (int *) malloc(size * sizeof(int));

   for(i = 0; i < size; i++){
      printf("Digite o %i item: ", i+1);
      scanf("%i", &arr[i]);
   }

   sort(arr, size);

   printf("\nDigite o valor que deseja pesquisar: ");
   scanf("%i", &value);

   pos = search(arr, 0, size - 1, value);
   if(pos >= 0){
      printf("\nValor encontrado %i vezes!", countOccurrences(arr, pos, size));
   } else {
      printf("\nValor não encontrado!");
   }
}