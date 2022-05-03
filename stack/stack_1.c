#include <stdlib.h>
#include <stdio.h>
#include "adt/stack.h"

char* letter(char letter){
  char* aux = (char*) malloc(sizeof(char));

  *aux = letter;
  return aux;
}

void printdata(void* data){
  printf("%c ", *((char*)data));
}

int main(){
  Stack* stack = new_stack();
  void* printFn = &printdata;
  
  push_stack(stack, letter('A'));
  push_stack(stack, letter('B'));
  push_stack(stack, letter('C'));
  push_stack(stack, letter('D'));
  push_stack(stack, top_stack(stack));
  pop_stack(stack);
  push_stack(stack, pop_stack(stack));
  pop_stack(stack);

  print_stack(stack, printFn);

  return 0;
}
