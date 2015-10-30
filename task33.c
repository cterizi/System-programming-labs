#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char str[31] = "start"; 
  char *lexiko[] = {"associate","bachelor","campus","college","course","credit","degree","dorm","enroll","exam","faculty","fail","fraternity","GPA","graduate","instructor","lecture","major","master","matriculate","notebook","notes","pass","PhD","postgraduate","prerequisite","professor","quiz"};
  int find, size, i;
  
  find = 0;
  size = sizeof(lexiko) / sizeof(char *);
  printf("Give a word or \"fin\" to exit : ");
  while(1){
    //fgets(str, 31, stdin);
    scanf("%s", str);
    if(strcmp(str, "fin") == 0){
      break;
    }
    for(i = 0; i < size; i++){
      if(strcmp(str, lexiko[i]) == 0){
        printf("The word : %s exists in dictionary.\n", str);
        find = 1;
        break;
      }
    }
    if(find != 1){
      printf("The word : %s does not exist in dictionary.\n", str);
    }
    printf("Give the next word :\n");
  }
  return 0;
}