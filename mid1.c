#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  int i, axia, sum;
  char *p;
  
  sum = 0;
  for(i = 1; i < argc; i++){
    p = argv[i];
    while(*p != '\0'){
      if((*p)>='0' && (*p)<= '9'){
        axia = *p - '0';
        sum = sum + axia;
      }
      p = p + 1;
    }
  }
  printf("SUM : %d\n", sum);
  return 0;
}