#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt/queue.h"
#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

void wait_for(int seconds){
  #ifdef _WIN32
    Sleep(1000 * seconds);
  #else
    sleep(seconds);
  #endif
}

void cls_screen(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

char* plate_pointer(char* license_plate){
  char* plate_pointer = (char*) malloc(strlen(license_plate) * sizeof(char));
  strcpy(plate_pointer, license_plate);
  return plate_pointer;
}

char continue_action(char* question){
  char op;

  printf("%s", question);
  scanf(" %c", &op);
  return op;
}

void register_car(Queue* cars){
  cls_screen();
  printf("\nCadastro de carros");
  if(queue_length(cars) == 5) {
    printf("\nFila cheia, por favor libere travessia!\n");
    return;
  }

  char license_plate[20];

  printf("\n Digite a placa do carro: ");
  scanf(" %[^\n]20s", license_plate);

  if(enqueue(cars, plate_pointer(license_plate))){
    printf("\nCarro cadastrado com sucesso!\n"); 
  } else {
    printf("\nOops! Tivemos um problema, tente novamente mais tarde.\n");
    return;
  }

  if(continue_action("\n\nDeseja cadastrar outro carro(S/N)? ") == 'S') register_car(cars);
}

void release(char *direction, Queue* queue){
  char* license_plate;

  printf("\n\tSentido %s", direction);
  if(!queue_empty(queue)){
    license_plate = (char*)dequeue(queue);
    printf("\n\t\tAtravessando Carro %s...", license_plate);
    free(license_plate);
  } else {
    printf("\n\t\tSem carros, aguardando...");
  }
  wait_for(5);
}

void release_cars(Queue* campos_guarus, Queue* guarus_campos){
  cls_screen();
  printf("\nTravessia Liberada");

  if(queue_empty(campos_guarus) && queue_empty(guarus_campos)){
    printf("\n\tSem carros para atravessar...");
  } else {
    release("Campos-Guarus", campos_guarus);
    release("Guarus-Campos", guarus_campos);
  }

  if(continue_action("\n\nDeseja prosseguir(S/N)? ") == 'S') release_cars(campos_guarus, guarus_campos);
}

int get_option(){
  int choice = 0;

  printf("\n=-=-=- Menu -=-=-=\n");
  printf("1. Cadastrar Campos-Guarus\n");
  printf("2. Cadastrar Guarus-Campos\n");
  printf("3. Liberar Travessia\n");
  printf("4. Sair\n");

  printf("Escolha uma opcao: ");
  scanf("%i", &choice);

  return choice;
}

int main(){
  int op = 0;
  Queue* campos_guarus = create_queue();
  Queue* guarus_campos = create_queue();

  while(op != 4){
    op = get_option();
    switch(op){
      case 1:
        register_car(campos_guarus);
        break;
      case 2:
        register_car(guarus_campos);
        break;
      case 3:
        release_cars(campos_guarus, guarus_campos);
        break;
      case 4:
        destroy_queue(campos_guarus);
        destroy_queue(guarus_campos);
        break;
      default:
        printf("Escolha invalida!\n");
    }
    cls_screen();
  }

  return 0;
}
