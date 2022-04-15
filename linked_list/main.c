#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct student {
  int id;
  float avg;
} Student;

int compareStudents(Student* student1, Student* student2){
  return (student1->avg > student2->avg);
}

void print_student(Student* student){
  printf("Student id: %i, avg: %.2f\n", student->id, student->avg);
}

void read_list(List* students){
  FILE *arq;
  int id;
  float avg;
  Student *new_student;
  void* fn = &compareStudents;

  arq = fopen("students.txt", "r");

  if(!arq) {
    fprintf(stderr, "File not found");
    exit(1);
  }
  while(fscanf(arq, "%i %f", &id, &avg) != EOF){
    new_student = (Student *) malloc(sizeof(Student));
    new_student->id = id;
    new_student->avg = avg;

    insert_node(students, new_student, fn);
  }
}

int main(){
  List students;
  void* prtfn = &print_student;
  students.first = NULL;
  students.count = 0;

  read_list(&students);
  print_l(students, prtfn);
  return 0;
}
