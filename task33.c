#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search(char *[], int **);


int main(){
  char str[31] = "start"; 
  char *lexiko[] = {"associate's degree","bachelor's degree","campus","community college","course","credit","degree","dorm","enroll","exam","faculty","fail","financial aid","fraternity","GPA","graduate","instructor","lecture","major","master's degree","matriculate","notebook","notes","pass","PhD","postgraduate","prerequisite","professor","quiz"};
  
  int find;
  printf("lexiko : %d\n", lexiko);
  while(strcmp(str, "fin\n") != 0){
    printf("Give a word :\n");
    fgets(str, 31, stdin);
    printf("str before call search = %d\n", str);
    //printf();
    find = search(lexiko, &str);
    //printf("*str = %d\n", *str);
    //*pointer = &(str[0]);
    //printf("*pointer = %d\n", *pointer);
  }
  return 0;
}

int search(char *a[], int **pointer){
  //*pointer = NULL;
  int i;
  char **l;
  char word[31];
  
  i = 0;
  //*l = &(a);
  printf("First element in lexiko : %s\n", *a);
  //printf("*l : %s\n", *l);
  printf("*pointer : %c\n", *(pointer+1));
  while(*(pointer+i) != '\0'){
    word[i] = *(pointer+i);
    i = i + 1;
    //*pointer ++;
  }
  printf("word : %s\n", word);
  return 0; 
}