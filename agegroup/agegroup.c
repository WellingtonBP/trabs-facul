#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Agegroup{
  int age;
  char **name;
  int qtt;
} AgeGroup;

typedef struct _Node{
  AgeGroup agegroup;
  struct _Node *left;
  struct _Node *right;
} Node;

Node *insert(Node *root, int age, char *name){
  Node *newnode = (Node*) malloc(sizeof(Node));

  newnode->agegroup.age = age;
  newnode->agegroup.qtt = 1;
  newnode->agegroup.name = (char**) malloc(sizeof(char*));
  newnode->agegroup.name[0] = (char*) malloc(20 * sizeof(char));
  strcpy(newnode->agegroup.name[0], name);

  if(!root){
    root = newnode;
  } else {
    Node *current = root;
    Node *parent = NULL;
    while(1){
      parent = current;

      if(current->agegroup.age > age){
        current = current->left;
        if(!current){
          parent->left = newnode;
          return root;
        }
      }else{
        current = current->right;
        if(!current){
          parent->right = newnode;
          return root;
        }
      }
    }
  }

  return root;
}

Node *search(Node *root, int age){
  Node *current = root;

  while(current){
    if(current->agegroup.age > age){
      current = current->left;
    }else if(current->agegroup.age < age){
      current = current->right;
    }else{
      return current;
    }
  }
}

void updatenode(Node *node, char *name){
  node->agegroup.qtt++;
  node->agegroup.name = (char**) realloc(node->agegroup.name, node->agegroup.qtt * sizeof(char*));
  node->agegroup.name[node->agegroup.qtt-1] = (char*) malloc(20 * sizeof(char));
  stpcpy(node->agegroup.name[node->agegroup.qtt-1], name);
}

void print_agegroups(Node *root){
  if(root){
    print_agegroups(root->left);
    printf("\n=-=-=- Age %i -=-=-=\n\n", root->agegroup.age);
    for(int i = 0; i < root->agegroup.qtt; i++){
      printf("  %s\n", root->agegroup.name[i]);
    }
    print_agegroups(root->right);
  }
}

int main(){
  Node *root = NULL;
  FILE *arq;
  int age;
  char name[20];

  arq = fopen("names.txt", "r");
  if(!arq){
    fprintf(stderr, "Nao foi possivel abrir o arquivo!");
    exit(1);
  }
  while(fscanf(arq, "%20s %i", name, &age) != EOF){
    Node *aux = search(root, age);
    if(aux){
      updatenode(aux, name);
    } else {
      root = insert(root, age, name);
    } 
  }

  print_agegroups(root);

  return 0;
}