#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_card(char *str);
int sum_digits(int);

int main(){
  char pin[51];
  int result;
  
  fgets(pin, 50, stdin);
  result = check_card(pin);
  if(result){
    printf("Valid card number!\n");
  }
  else{
    printf("Invalidity card number!\n");
  }
  return 0;
}

int check_card(char *str){
  int pointer, i, value, add_dig, sum;
  char *p;
  
  pointer = 0;
  value = 0;
  while(*str){
    pointer = pointer + 1;
    str++;
  }
  str = str - 2;
  p = str;
  pointer = pointer - 1;
  i = 1;
  while(*p != '\0'){
    if((i%2) == 0){
      value = *p - '0';
      value = value * 2;
      if(value > 9){
        add_dig = sum_digits(value);
        *p = add_dig + '0';
      }
      else{
        *p = value + '0';
      }
    }
    i = i + 1;
    p = p - 1;
  }
  p = p + 1;
  
  sum = 0;
  for(i = 1; i <= pointer; i++){
    sum = sum + (*p - '0');
    p = p + 1;
  }
  
  if(sum % 10 == 0){
    return 1;
  }
  return 0;
}

int sum_digits(int number){
  int sum, division, mod;
  
  sum = 0;
  division = 1;
  while(division != 0){
    division = number / 10;
    mod = number % 10;
    sum = sum + mod;
    number = division;
  }
  return sum;
}