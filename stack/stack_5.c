#include <stdlib.h>
#include <stdio.h>
#include "adt/stack.h"

int* number(int number){
  int* aux = (int*) malloc(sizeof(int));

  *aux = number;
  return aux;
}

void fill_stack(Stack* stack, int decimal_number){
  while(decimal_number){
    push_stack(stack, number(decimal_number % 2));
    decimal_number /= 2;
  }
}

void printdata(void* data){
  printf("%i ", *((int*)data));
}

int main(){
  Stack* stack = new_stack();
  void* printFn = &printdata;
  int decimal_number;

  printf("Enter decimal number: ");
  scanf("%i", &decimal_number);
  
  fill_stack(stack, decimal_number);

  print_stack(stack, printFn);
  return 0;
}
