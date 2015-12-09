#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  int n, *array, t, i, sum;
  float mo;
  
  srand(time(NULL));
  sum = 0;
  printf("Dwse to megethos tou pinaka : ");
  scanf("%d", &n);
  array = (int *)malloc(n * sizeof(int));
  printf("Ta stoixeia tou pinaka einai : ");
  for(i = 0; i < n; i++){
    *(array+i) = rand() % 101;
    sum = sum + *(array+i);
    printf("%d  ", *(array+i));
  }
  printf("\n");
  mo = ((float) sum )/ n;
  printf("Mesos oros stoixeiwn pinaka : %f", mo);
  return 0;
}
