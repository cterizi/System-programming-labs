#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50

struct student{
  char name[SIZE];
  int am;
  float degree;
};
typedef struct student student_t;

//prototypes
student_t *create(int number);
void print_details(student_t *table, int number);
float average(student_t *table, int number);
void show_failed(student_t *table, int number);
void changed_failed_name(student_t *table, int number);
void write_to_file(student_t *table, int students_number);
student_t *create_from_file(FILE *output, int *number);

int main(){
  char buf[SIZE];
  int students_number;
  student_t *table;
  float avg_value;
  FILE *output;
  
  //output = fopen("students.txt", "w");
  output = fopen("students.txt", "r");
  if(output == NULL){
    printf("Dwse ton arithmo twn mathitwn : ");
    fgets(buf, SIZE, stdin);
    students_number = atoi(buf);
    
    if(students_number <= 0){
      printf("ERROR : lathos arithmos mathhtwn");
      return 0;
    }
    
    table = create(students_number);
  }
  else{
    //Read from students.txt
    printf("ELSE");
    create_from_file(output, &students_number);
    fclose(output);
  }
  
  
  table = create(students_number);
  printf("\n");
  printf("\n");
  printf("Details \n");
  print_details(table, students_number);
  
  avg_value = average(table, students_number);
  printf("AVERAGE : %f\n ", avg_value);
  printf("\n");
  printf("Students who failed : \n");
  show_failed(table, students_number);
  printf("\n");
  printf("New names : \n");
  changed_failed_name(table, students_number);
  show_failed(table, students_number);
  write_to_file(table, students_number);
  
  fclose(output);
  //free malloc
  free(table);
  
  return 0;
}


student_t *create(int number){
  student_t *table;
  int i;
  char buf[SIZE];
  
  table = (student_t *)malloc((number)*(sizeof(student_t)));
  if(table == NULL){
    exit(1);
  }
  
  for(i = 0; i < number; i++){
    printf("NAME : ");
    fgets(buf, SIZE, stdin);
    //pairnei kai to \n
    //TODO , na mhn emfanizetai to new line
    strcpy(table[i].name, buf);
    
    printf("AM : ");
    fgets(buf, SIZE, stdin);
    table[i].am = atoi(buf);
    
    printf("Vathmos : ");
    fgets(buf, SIZE, stdin);
    table[i].degree = atof(buf);
    
  }
  return table;
}


void print_details(student_t *table, int number){
  int i;
  
  for(i = 0; i < number; i++){
    printf("Name : %s\n", table[i].name);
    printf("AM : %d\n", table[i].am);
    printf("Degree : %f\n", table[i].degree);
    printf("------------------------\n");
  }
  return ;
}


float average(student_t *table, int number){
  float avg, sum;
  int i;
  
  sum = 0;
  for(i = 0; i < number; i++){
    sum = sum + table[i].degree;
  }
  avg = sum / (float)number;
  return avg;
}


void show_failed(student_t *table, int number){
  int i, count ;
  
  count = 0;
  for(i = 0; i < number; i++){
    if(table[i].degree < 10){
      count = count + 1;
      printf("%d) %s\n", count , table[i].name);
    }
  }
  return ;
}


void changed_failed_name(student_t *table, int number){
  int i;
  
  for(i = 0; i < number; i++){
    if(table[i].degree < 10){
      strcat(table[i].name, " (fialed)");
    }
  }
  
  return;
}


void write_to_file(student_t *table, int students_number){
  int i;
  FILE *out;
  
  out = fopen("students.txt", "w");
  if(out == NULL){
    fprintf(out, "%s\n", "File can't open normally");
    exit(1);
  }
  fprintf(out, "Number of students : %d\n", students_number);
  for(i = 0; i < students_number; i++){
    fprintf(out, "%d) Name: %s -- AM: %d -- Vathmos: %f \n", (i+1), table[i].name, table[i].am, table[i].degree);
  }
  
  fclose(out);
  return ;
}


student_t *create_from_file(FILE *output, int *number){
  int i;
  student_t *table;
  char buf[SIZE];
  
  fgets(buf, SIZE, output);
  *number = atoi(buf);
  
  table = (student_t *)malloc((*number)*(sizeof(student_t *)));
  if(table == NULL){
    exit(1);
  }
  
  for(i = 0; i < *number; i++){
    fgets(buf, SIZE, output);
    //xana to idio problhma 
    //prepei na vgalw to new line
    strcpy(table[i].name, buf);
    
    fgets(buf, SIZE, output);
    table[i].am = atoi(buf);
    
    fgets(buf, SIZE, output);
    table[i].degree = atof(buf);
  }
  return table;
}