#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

char *dates[N] = {
	"12/12",
	"6/12",
	"30/11",
	"12/6",
	"13/5"
};
char *names[N] = {
	"Spiros, Spiridoula",
	"Nikolaos, Nikoletta, Niki",
	"Andreas, Andriana, Andromaxi, Maxi",
	"Onoufrios",
	"Glykeria"
};

int main(int argc, char *argv[]){
  int i, found, found2;
  char *ret;
  
  if(argc < 2){
    printf("Wrong arguments\n");
    exit(1);
  }
  found = 0;
  if(strcmp(argv[1], "date") == 0){
    for(i = 0; i < N; i++){
      if(strcmp(argv[2], dates[i]) == 0){
        printf("Celebrate in %s : %s\n", argv[2], names[i]);
        found = 1;
      }
    }
    if(found == 0){
      printf("Anyone celebrate in %s\n", argv[2]);
    }
  }
  else if(strcmp(argv[1], "name") == 0){
    for(i = 0; i < N; i++){
      ret = strstr(names[i], argv[2]);
      if(ret != NULL){
        printf("%s celebrate in %s\n", argv[2], dates[i]);
        printf("Also, the same date celebrates %s", names[i]);
        found2 = 1;
        break;
      }
    }
    if(found2 == 0){
        printf("Don't know when %s celebrates", argv[2]);
      }
  }
  else{
    printf("Your argument is not either \"date\" nor \"name\" ");
  }
  return 0;
}