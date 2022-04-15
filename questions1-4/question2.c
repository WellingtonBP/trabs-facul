#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void merge(int *arr, int start, int middle, int end){
   int *left, *right, l = 0, r = 0, i = 0, size_l = 0, size_r = 0;

   size_l = middle - start;
   size_r = end - middle;
   left = (int *) malloc(size_l * sizeof(int));
   right = (int *) malloc(size_r * sizeof(int));
   for(i = 0; i < size_l; i++) left[i] = arr[start+i];
   for(i = middle; i < end; i++) right[r++] = arr[i];
   r = 0;
   for(i = start; i < end; i++){
      if(l >= size_l) {
         arr[i] = right[r++];
      } else if(r >= size_r) {
        arr[i] = left[l++]; 
      } else if(left[l] > right[r]){
         arr[i] = right[r++];
      } else {
         arr[i] = left[l++];
      }
   }

   free(left);
   free(right);
}

void mergeSort(int *arr, int start, int end){
   int middle = 0;
   if(end - start > 1) {
      middle = (end + start) / 2;
      mergeSort(arr, start, middle);
      mergeSort(arr, middle, end);
      merge(arr, start, middle, end);
   }
}

void main(){
   int *arrays[2], *unionArr, sizes[2], i = 0, j = 0, totalSize = 0;

   printf("Digite o tamanho do primeiro array: ");
   scanf("%i", &sizes[0]);
   printf("Digite o tamanho do segundo array: ");
   scanf("%i",  &sizes[1]);

   totalSize = sizes[0] + sizes[1];

   unionArr = (int *) malloc(totalSize * sizeof(int));

   for(i = 0; i < 2; i++){
      arrays[i] = (int *) malloc(sizes[i] * sizeof(int));
      printf("\n-> Itens do %i array: \n", i+1);
      for(j = 0; j < sizes[i]; j++){
         printf("Digite o %i item: ", j+1);
         scanf("%i", &arrays[i][j]);
      }
      mergeSort(arrays[i], 0, sizes[i]);
   }

   for(i = 0; i < 2; i++){
      printf("\nArray %i: ", i+1);
      for(j = 0; j < sizes[i]; j++) printf("%i ", arrays[i][j]);
   }

   memcpy(unionArr, arrays[0], sizes[0] * sizeof(int));
   memcpy(unionArr + sizes[0], arrays[1], sizes[1] * sizeof(int));
   merge(unionArr, 0, sizes[0], totalSize);

   printf("\n\nExibindo união dos arrays: \n");
   for(i = 0; i < totalSize; i++) printf("%i ", unionArr[i]);

   free(arrays[0]);
   free(arrays[1]);
   free(unionArr);
}