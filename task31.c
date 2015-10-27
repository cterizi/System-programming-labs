#include <stdio.h>
void search(int [], int, int, int **);

int main(){
	int table[] = {4,5,2,7};
	int size, value;
  int *p;
	
	value = 7;
  p = table;
	size = sizeof(table) / sizeof(int);
	search(table, size, value, &p);
	if(p != NULL){
		printf("To stoixeio %d vrisketai ston pinaka kai h dieythhnsh tou einai %d\n", *p, p);
	}
	else{
		printf("To stoixeio %d den uparxei ston pinaka", value);
	}
	return 0;
}

void search(int a[], int size, int number, int **pointer){
	int i;

  *pointer = NULL;
	for(i = 0; i < size; i++){
		if(a[i] == number){
			*pointer = &(a[2]); 
		}
	}
	return;
}
