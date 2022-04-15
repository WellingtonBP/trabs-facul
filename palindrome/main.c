#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_palindrome(char *str, int size, int pos){
  if(pos >= size - pos) return 1;
  if(tolower(str[pos]) != tolower(str[size-pos])) return 0; 
  return is_palindrome(str, size, pos+1);
}

void remove_spaces(char* str){
  char *aux;
  int i, len, j = 0;
 
  len = strlen(str);
  aux = (char*) malloc(len * sizeof(char));
  strcpy(aux, str);

  for(i = 0; i < len; i++){
    if(!isspace(aux[i])){
      str[j++] = aux[i];
    }
  }
  str[j] = '\0';
}

int main(){
  char str[200];

  printf("Type an string: ");
  scanf(" %[^\n]200s", str);

  remove_spaces(str);

  printf("Is palindrome: %s\n", (is_palindrome(str, strlen(str)-1, 0) ? "true" : "false"));
  return 0;
}
