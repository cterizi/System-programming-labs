#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int sum, i, j;
    char *new;
    
    sum = 0;
    for(i = 1; i < argc; i++){
      sum = sum + strlen(argv[i]);
    }
    new = (char *)malloc((sum + 1) * sizeof(char));
    for(i = 1; i < argc; i++){
      strcpy(new, argv[i]);
      new = new + strlen(argv[i]);
    }
    *(new + 1) = '\0';
    new = new - sum;
    printf("new : %s\n", new);
    return 0;
}