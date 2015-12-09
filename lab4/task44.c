#include <stdio.h>
#include <stdlib.h>
int **pascal(int n);

int main(int argc, char *argv[]){
  int n, **res, i, j;
  
  if(argc <= 1){
    printf("Error with arguments <= 1");
    return 0;
  }
  else if(argc == 2){
    n = atoi(argv[1]);
    res = pascal(n);
    if(res == NULL){
      printf("Error");
      return 0;
    }
  }
  else{
    printf("Error with arguments >2");
    return 0;
  }
  for(i = 0; i < n; i++){
    for(j = 0; j <= i; j++){
      printf("%d  ", res[i][j]);
    }
    printf("\n");
  }
  
  for(i = 0; i < n; i++){
    free(res[i]);
  }
  free(res);
  return 0;
}

int **pascal(int n){
  int **triangle, i, j;
  
  triangle = (int **)malloc(n * sizeof(int *));
  if(triangle == NULL){
    printf("Something went wrong with malloc\n");
    return NULL;
  }
  for(i = 1; i <= n; i++){
    triangle[i-1] = (int *)malloc(i * sizeof(int));
    if(triangle[i-1] == NULL){
      printf("Something went wrong with malloc\n");
      return NULL;
    }
  }
  //triangle[0][0] = 1;
  for(i = 0; i < n; i++){
    triangle[i][0] = 1;
    for(j = 1; j < i; j++){
      triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
    }
    triangle[i][i] = 1;
  }
  return triangle;
}