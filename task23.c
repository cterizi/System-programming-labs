#include <stdio.h>
int * search(int [], int, int);


int main(){
	int table[] = {4,5,2,7};
	int size, value, *pa;
	
	//pa = &table[0];
	//printf("%d\n", pa);
	value = 0;
	size = sizeof(table) / sizeof(int);
	pa = search(table, size, value);
	if(!NULL){
		//printf("%d\n", *pa);
		//printf("%d\n", pa);
		printf("To stoixeio %d vrisketai ston pinaka kai h dieythhnsh tou einai %d\n", *pa, pa);
	}
	else{
		printf("To stoixeio %d den uparxei ston pinaka", value);
	}
	return 0;
}

int * search(int a[], int size, int number){
	int *pa, i;

	pa = &a[0];
	//printf("%d\n", pa);
	for(i = 0; i < size; i++){
		if(a[i] == number){
			pa = pa + i; 
			return pa; 
		}
	}
	return NULL;
}
