#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *fd, *pos, *neg;
  char buf[5], str[5];
  int first_variable, *table, i, count_pos, count_neg, sum;
  long pos_thesi;
  
  fd = fopen("data.txt", "r");
  pos = fopen("positive.txt", "w+");
  neg = fopen("negative.txt", "w");
  if(fd == NULL){
    printf("ERROR : can't open file 'data.txt' ");
    return (-1);
  }
  
  if(pos == NULL){
    printf("ERROR : can't open file 'positive.txt' ");
    fclose(fd);
    return(-1);
  }
  
  if(neg == NULL){
    printf("ERROR : can't open file 'negative.txt' ");
    fclose(fd);
    fclose(pos);
    return(-1);
  }
  
  first_variable = atoi(fgets(buf, 5, fd));
  table = (int *)malloc(first_variable * sizeof(int));
  i = 0;
  
  count_neg = 0;
  count_pos = 0;
  while(fgets(buf, 5, fd) != NULL){
    table[i] = atoi(buf);
    if(table[i] > 0){
      count_pos = count_pos + 1;
    }
    else if(table[i] < 0){
      count_neg = count_neg + 1;
    }
    else{
      continue;
    }
    i = i + 1;
  }
  
  sprintf(str, "%d", count_pos);
  fputs(str, pos);
  fputs("\n", pos);
  sprintf(str, "%d", count_neg);
  fputs(str, neg);
  fputs("\n", neg);
    
  //write into the files
  for(i = 0; i < first_variable; i++){
    if(table[i] > 0){
      sprintf(str, "%d", table[i]);
      fputs(str, pos);
      fputs("\n", pos);
    }
    else if(table[i] < 0){
      sprintf(str, "%d", table[i]);
      fputs(str, neg);
      fputs("\n", neg);
    }
    else{
      continue;
    }
  }
  
  //vlepoume se poia thesi eimaste
  pos_thesi = ftell(pos);
  //printf("ftell : %d\n", pos_thesi);
  
  //phgainoume stin prwti thesi tou arxeiou
  fseek(pos, -pos_thesi, SEEK_END);
  pos_thesi = ftell(pos);
  //printf("ftell : %d\n", pos_thesi);
  
  sum = 0;
  while(fgets(buf, 5, pos) != NULL){
    sum = sum + atoi(buf);
  }
  printf("SUM : %d\n", sum);
  //close the files
  fclose(fd);
  fclose(pos);
  fclose(neg);
  //free malloc
  free(table);
  return 0;
}