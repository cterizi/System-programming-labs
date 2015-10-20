#include <stdio.h>
int compare(int, int);
void swap(int *, int *);
void bubblesort(int[], int);

int main(){
	int table[] = {2,5,4,3,7};
	int i, a, b, size;

	/*for(i = 0; i < 5; i++){
		printf("%d \n", table[i]);
	}
	printf("---------\n");
	int t ;
	t = compare(4,3);
	printf("---------\n");
	printf("%d\n", t);
	t = compare (4,4);
	printf("---------\n");
	printf("%d\n", t);
	t = compare(3,7);
	printf("---------\n");
	printf("%d\n", t);*/
	/*a = 3;
	b = 4;
	printf("a = %d, b = %d \n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d \n", a, b);*/
	size = sizeof(table) / sizeof(int);
	bubblesort(table, size);
	for(i = 0; i < 5; i++){
		 printf("%d \n", table[i]);
	}
	return 0;
}

int compare(int x, int y){
	if(x > y){
		return 1;
	}
	else if(x == y){
		return 0;
	}
	return -1;
}

void swap(int *x1, int *x2){
	int temp;
	
	temp = *x1;
	*x1 = *x2;
	//temp = *x1;
	*x2 = temp;
}

void bubblesort(int a[], int size){
	int i, j, l, com;
	l = size - 1;

	for(i = 0; i <= l; i++){
		for(j = l; j >= i; j--){
			com = compare(a[j], a[j-1]);
			if(com == -1){
				swap(&a[j], &a[j-1]);
			}
		}
	}
}
