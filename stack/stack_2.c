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
  Stack* x = new_stack();
  Stack* y = new_stack();
  Stack* z = new_stack();
  void* printFn = &printdata;

  push_stack(x, letter('A'));
  push_stack(x, letter('B'));
  push_stack(x, letter('C'));
  push_stack(x, letter('D'));
  push_stack(y, pop_stack(x));
  push_stack(y, pop_stack(x));
  push_stack(y, pop_stack(x));
  push_stack(z, pop_stack(x));
  push_stack(x, pop_stack(y));
  push_stack(z, pop_stack(y));
  push_stack(z, pop_stack(x));
  push_stack(z, pop_stack(y));

  print_stack(z, printFn);

  return 0;
}
