#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "adt/stack.h"

char* letter(char letter){
  char* aux = (char*) malloc(sizeof(char));

  *aux = letter;
  return aux;
}

void fill_stack(Stack* stack, char* word){
  int len = strlen(word);
  int i = 0;

  for(i = 0; i<len; i++){
    push_stack(stack, letter(word[i]));
  }
}

int is_palindrome(Stack* stack, char* word){
  int len = strlen(word);
  int i = 0;

  for(i = 0; i<len; i++){
    if(*((char*)pop_stack(stack)) != word[i]) return 0;
  }

  return 1;
}

int main(){
  Stack* stack = new_stack();
  char word[20];
  
  printf("Enter a word: ");
  scanf(" %[^\n]20s", word);

  fill_stack(stack, word);

  if(is_palindrome(stack, word)){
    printf("A PALAVRA E PALINDROMA");
  }else{
    printf("A PALAVRA NAO E PALINDROMA");
  }

  return 0;
}
