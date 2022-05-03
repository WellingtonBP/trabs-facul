#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "adt/stack.h"

int* number(int number){
  int* aux = (int*) malloc(sizeof(int));

  *aux = number;
  return aux;
}

void fill_stack(Stack* stack, int size){
  int i;

  srand(time(NULL));
  for(i = 0; i<size; i++){
    push_stack(stack, number(rand()));
  }
}

void split_in_even_or_odd(Stack* stack, Stack* even, Stack *odd){
  int aux;

  while(!empty_stack(stack)){
    aux = *((int*)pop_stack(stack));
    if(aux % 2 == 0){
      push_stack(even, number(aux));
    } else {
      push_stack(odd, number(aux));
    }
  }
}

void printdata(void* data){
  printf("%i ", *((int*)data));
}

int main(){
  Stack* stack = new_stack();
  Stack* even = new_stack();
  Stack* odd = new_stack();
  void* printFn = &printdata;
  int size;

  printf("Enter stack size: ");
  scanf("%i", &size);
  
  fill_stack(stack, size);
  split_in_even_or_odd(stack, even, odd);

  printf("EVEN NUMBERS\n");
  print_stack(even, printFn);

  printf("\nODD NUMBERS\n");
  print_stack(odd, printFn);
  return 0;
}
