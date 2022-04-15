#include <stdio.h>
#include <stdlib.h>

typedef struct _Freqsymb {
  char symb;
  int freq;
  struct _Freqsymb *next;
} Freqsymb;

typedef struct _List {
  int n;
  Freqsymb *first;
} List;

void insert(List *symbols, char symbol){
  int inserted = 0;
  Freqsymb *newSymbol = (Freqsymb*) malloc(sizeof(Freqsymb));
  newSymbol->freq = 1;
  newSymbol->symb = symbol;
  newSymbol->next = NULL;

  if(!symbols->first){
    symbols->first = newSymbol;
  }
   else {
    Freqsymb *current = symbols->first;
    Freqsymb *previews = NULL;
    while(!inserted) {
      if(current->symb > symbol){
        newSymbol->next = current;
        if(previews){
          previews->next = newSymbol;
        } else {
          symbols->first = newSymbol;
        }
        inserted = 1;
      } else if(current->symb < symbol){
        previews = current;
        current = current->next;
        if(!current){
          current = newSymbol;
          previews->next = current;
          inserted = 1;
        }
      } else {
        current->freq++;
        free(newSymbol);
        inserted = 1;
       }
    }
  }
}

void print_l(List symbols){
  Freqsymb *elem = symbols.first;

  while(elem){
    printf("Symbol: %c\tFrequency: %i\n", elem->symb, elem->freq);
    elem = elem->next;
  }
}

int main(){
  FILE *arq;
  char symb;
  List symbols;

  symbols.first = NULL;

  arq = fopen("arquivo.txt", "r");
  if(!arq){
    fprintf(stderr, "Arquivo não encontrado");
  }
  while(!feof(arq)){
    symb = fgetc(arq);
    insert(&symbols, symb);
  }

  print_l(symbols);
  return 0;
}