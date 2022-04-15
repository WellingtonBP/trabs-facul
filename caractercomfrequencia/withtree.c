#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char symb;
  int freq;
  struct Node *left;
  struct Node *right;
} Node;

Node *insert(Node *root, char symb){
  Node *new = (Node*) malloc(sizeof(Node));

  new->symb = symb;
  new->freq = 1;
  new->right = NULL;
  new->left = NULL;
  if(root == NULL){
    root = new;
  } else {
    Node *current = root;
    Node *parent = NULL;

    while(1){
      parent = current;

      if(symb < parent->symb){
        current  = current->left;

        if(current == NULL){
          parent->left = new;
          return root;
        }
      } else {
        current = current->right;
        
        if(current == NULL) {
          parent->right = new;
          return root;
        }
      }
    }
  }
  
  return root;
}

Node *search(Node *root, char symb) {
  Node *current = root;

  while(current) {
      if (symb < current->symb) {
          current = current->left;
      } else if (symb > current->symb) {
          current = current->right;
      } else {
          return current;
      }
  }
}

void print_tree(Node *root) {
  if(root) {
    print_tree(root->left);
    printf("Symbol: %c\tFreq: %i\n", root->symb, root->freq);
    print_tree(root->right);
  }
}

int main(){
  Node *root = NULL;
  FILE *arq;
  char symb;

  arq = fopen("arquivo.txt", "r");
  if(!arq){
    fprintf(stderr, "Arquivo não encontrado");
    exit(0);
  }
  while (!feof(arq)){
    symb = fgetc(arq);
    Node *exist = search(root, symb);
    if(exist){
      exist->freq++;
    }else{
      root = insert(root, symb);
    }
  };

  print_tree(root);

  return 0;
}