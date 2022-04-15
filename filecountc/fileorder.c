#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
  char name[30];
  int qtdChar, found;
};

struct file *files;
int qtdFiles = 0;

void saveFileList(){
  FILE *fileList;
  int i;

  fileList = fopen("listaDeArquivos.txt", "w");

  if(fileList != NULL){
    for(i = 0; i < qtdFiles; i++){
      fprintf(fileList, "%s%s", files[i].name, i+1 < qtdFiles ? "\n" : "");
    }
    fclose(fileList);
  }else {
    printf("Lista nao encontrada :(\n");
  }
}

void orderFiles(){
  int i, j;
  struct file aux;

  for(i = 1; i < qtdFiles; i++){
    for(j = 0; j < qtdFiles - i; j++){
      if(files[j].qtdChar > files[j+1].qtdChar){
        aux = files[j];
        files[j] = files[j+1];
        files[j+1] = aux;
      }
    }
  }
}

int characterCount(FILE* arq){
  int count = 0;
  char chr;

  while(!feof(arq)){
    chr = fgetc(arq); 
    if(chr != ' ' && chr != '\n') count++;
  }

  return !count ? 0 : count - 1;
}

void loadFiles(){
  FILE *arq, *fileList;
  int cont = 0;
  
  fileList = fopen("listaDeArquivos.txt", "r");
  if(fileList == NULL){
    fprintf(stderr, "Lista não encontrada");
    exit(1);
  }

  files = (struct file *) malloc(sizeof(struct file));

  while (!feof(fileList)) {
    if(qtdFiles){
      files = (struct file *) realloc(files, (qtdFiles+1) * sizeof(struct file));
    }

    fscanf(fileList, "%s", files[qtdFiles].name);
    if(strcmp(files[cont].name, "")){
      qtdFiles++; 
      arq = fopen(files[cont].name, "r");
      if(arq != NULL){
        files[cont].found = 1;  
        files[cont].qtdChar = characterCount(arq);
        fclose(arq);
      } else {
        files[cont].found = 0;
        files[cont].qtdChar = 0;
      }
      cont++;
    }
  }

  fclose(fileList);
}

void readFile(){
  FILE *arq;
  int index, i;

  if(!qtdFiles){
    printf("Nenhum arquivo encontrado na lista!\n\n");
    return;
  }

  printf("Escolha um arquivo\n");
  for(i = 0; i < qtdFiles; i++){
    printf("%i - %s (quantidade de caracteres: %i) %s\n", i+1, files[i].name, files[i].qtdChar, !files[i].found ? "(nao encontrado)" : "");
  }
  printf("\nArquivo: ");
  scanf("%i", &index);
  index--;

  arq = fopen(files[index].name, "r");

  if(arq != NULL){
    while(!feof(arq)){
      printf("%c", fgetc(arq));
    }

    if(!files[index].found){
      files[index].found = 1;
      files[index].qtdChar = characterCount(arq);
      orderFiles();
    }

    fclose(arq);
  }
  else {
    fprintf(stderr, "Arquivo nao encontrado");
    if(files[index].found){
      files[index].found = 0;
      files[index].qtdChar = 0;
      orderFiles();
    }
  }
  printf("\n\n");
}

void addFile(){
  FILE *arq;
  int index;

  qtdFiles++;
  index = qtdFiles-1;
  files = (struct file *) realloc(files, qtdFiles * sizeof(struct file));
  printf("Digite o nome do arquivo: ");
  scanf(" %[^\n]", files[index].name);

  arq = fopen(files[index].name, "r");

  if(arq != NULL) {
    files[index].found = 1;
    files[index].qtdChar = characterCount(arq);
    fclose(arq);
  } else {
    files[index].found = 0;
    files[index].qtdChar = 0;
  }
  orderFiles();
  printf("Arquivo adicionado! \n\n");
}

void removeFile(){
  int index, i, j = 0;
  struct file *aux;

   if(!qtdFiles){
    printf("Nenhum arquivo encontrado na lista!\n\n");
    return;
  }

  qtdFiles--;

  aux = (struct file *) malloc(qtdFiles * sizeof(struct file));

  printf("Escolha um arquivo\n");
  for(i = 0; i <= qtdFiles; i++){
    printf("%i - %s\n", i+1, files[i].name);
  }
  printf("\nArquivo: ");
  scanf("%i", &index);
  index--;

  for(i = 0; i <= qtdFiles; i++){
    if(i != index){
      aux[j++] = files[i];
    }
  }

  free(files);
  files = aux;

  printf("Arquivo removido\n\n");
}

void menu(){
  int op = 1, subOp = 1;

  printf("=-=-=-=-=-=-=-=-=-=\nEscolha uma opcao\n=-=-=-=-=-=-=-=-=-=\n");

  while(op != 4){
    printf("1 - Ler arquivo\n");
    printf("2 - Adicionar arquivo\n");
    printf("3 - Remover Arquivo\n");
    printf("4 - Salvar e sair\n\n");
    printf("Sua escolha: ");
    scanf("%i", &op);  
    printf("\n");

    switch(op){
      case 1:
        readFile();
        break;
      case 2:
        addFile();
        break;
      case 3:
        removeFile();
        break;
      case 4:
        saveFileList();
        printf("Ate mais!");
        break;
      default:
        printf("Opcao Invalida\n\n");
        break;
    }
  }
}

void main(){
  loadFiles();
  orderFiles();
  menu();
  
  free(files);
}